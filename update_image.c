/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 11:16:20 by tgouedar          #+#    #+#             */
/*   Updated: 2019/04/03 13:38:42 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_manipulation.h"
#include <stdio.h>

static void
	ft_calcul(t_data *win, int pt1[2], int pt2[2])
{
	int		tmp;

	tmp = (int)(win->zoom * (win->pixel[pt1[0]][pt1[1]][0] - win->origin[0])
			+ win->offset_origin_x);
	pt1[1] = (int)(win->zoom * (win->pixel[pt1[0]][pt1[1]][1] - win->origin[1])
			+ win->offset_origin_y);
	pt1[0] = tmp;
	tmp = (int)(win->zoom * (win->pixel[pt2[0]][pt2[1]][0] - win->origin[0])
			+ win->offset_origin_x);
	pt2[1] = (int)(win->zoom * (win->pixel[pt2[0]][pt2[1]][1] - win->origin[1])
			+ win->offset_origin_y);
	pt2[0] = tmp;
}

static void
	ft_bresenham(t_data *win, int pt1[2], int pt2[2], unsigned int pixel[2])
{
	unsigned int		cnt;
	unsigned int		i;
	float				pente;
	float				err;

	i = 0;
	err = 0.0;
	pente = (float)(pt2[1] - pt1[1]) / (float)(pt2[0] - pt1[0]);
	pente *= (pt2[0] > pt1[0]) ? 1 : -1;
	cnt = (pt2[0] - pt1[0] > 0) ? pt2[0] - pt1[0] : pt1[0] - pt2[0];
	while (i++ < cnt)
	{
		if (!(pixel[0] >= win->win_height) && !(pixel[1] >= win->win_width))
			win->im_data[(pixel[0] + win->win_height * pixel[1]) * 4] = -1;
		err += pente;
		while ((err > 1.0) || (err < -1.0))
		{
			pixel[1] += (err > 0.0) ? 1 : -1;
			err += (err > 0.0) ? -1.0 : 1.0;
			if (!(pixel[0] >= win->win_height)
			&& !(pixel[1] >= win->win_width))
				win->im_data[(pixel[0] + win->win_height * pixel[1]) * 4] = -1;
		}
		pixel[0] += (pt2[0] > pt1[0]) ? 1 : -1;
	}
}

void
	ft_draw_line_b(t_data *win, int pt1[2], int pt2[2])
{
	unsigned int		pixel[2];
	unsigned int		cnt;
	unsigned int		i;

	i = 0;
	ft_calcul(win, pt1, pt2);
	pixel[0] = pt1[0];
	pixel[1] = pt1[1];
	if (pt1[0] == pt2[0])
	{
		cnt = (pt2[1] - pt1[1] > 0) ? pt2[1] - pt1[1] : pt1[1] - pt2[1];
		while (i++ < cnt)
		{
			if (!(pixel[0] >= win->win_height) && !(pixel[1] >= win->win_width))
				win->im_data[(pixel[0] + win->win_height * pixel[1]) * 4] = -1;
			pixel[1] += (pt2[1] - pt1[1] > 0) ? 1 : -1;
		}
	}
	else
		ft_bresenham(win, pt1, pt2, pixel);
	if (!(pixel[0] >= win->win_height) && !(pixel[1] >= win->win_width))
		win->im_data[(pixel[0] + win->win_height * pixel[1]) * 4] = -1;
}

void
	ft_fill_image(t_data *win)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	while (i < win->tab_height)
	{
		j = 0;
		while (j < win->tab_width)
		{
			if (i + 1 < win->tab_height)
				ft_draw_line_b(win, (int[]){i, j}, (int[]){i + 1, j});
			if (j + 1 < win->tab_width)
				ft_draw_line_b(win, (int[]){i, j}, (int[]){i, j + 1});
			j++;
		}
		i++;
	}
}

void
	ft_create_image(t_data *win)
{
	int		bpp;
	int		s_l;
	int		endian;
	void	*new_im_ptr;

	new_im_ptr = mlx_new_image(win->mlx_ptr, win->win_height, win->win_width);
	win->im_data = mlx_get_data_addr(new_im_ptr, &(bpp), &(s_l), &(endian));
	ft_fill_image(win);
	mlx_put_image_to_window(win->mlx_ptr, win->id_ptr, new_im_ptr, 0, 0);
	affiche_commandes(win);
}
