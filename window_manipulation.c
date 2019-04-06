/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:39:54 by tgouedar          #+#    #+#             */
/*   Updated: 2019/04/04 18:16:41 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_manipulation.h"

static float	ft_find_dim(t_data *win, int flag)
{
	unsigned int		i;
	unsigned int		j;
	float				max;
	float				min;

	i = 0;
	max = (win->pixel)[0][0][flag];
	min = (win->pixel)[0][0][flag];
	while (i < win->tab_height)
	{
		j = 0;
		while (j < win->tab_width)
		{
			if ((win->pixel)[i][j][flag] > max)
				max = (win->pixel)[i][j][flag];
			if ((win->pixel)[i][j][flag] < min)
				min = (win->pixel)[i][j][flag];
			j++;
		}
		i++;
	}
	win->origin[flag] = min + (max - min) / 2.0;
	return (max - min);
}

void			ft_init_zoom(t_data *win)
{
	int		dim_max;
	float	dim[2];

	dim[0] = ft_find_dim(win, 0);
	dim[1] = ft_find_dim(win, 1);
	dim_max = (dim[0] / FS_HEIGHT) > (dim[1] / FS_WIDTH) ? 0 : 1;
	win->zoom = (dim_max) ? (float)(FS_WIDTH - 2 * DEF_OFFSET) / dim[1]
							: (float)(FS_HEIGHT - 2 * DEF_OFFSET) / dim[0];
	win->offset_origin_x = FS_HEIGHT / 2;
	win->offset_origin_y = FS_WIDTH / 2;
}

void			ft_free_pixel_tab(t_data *win)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	while (i < win->tab_height)
	{
		j = 0;
		while (j < win->tab_width)
		{
			free(win->pixel[i][j++]);
		}
		free(win->pixel[i]);
		i++;
	}
	free(win->pixel);
}
