/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:59:33 by tgouedar          #+#    #+#             */
/*   Updated: 2019/04/06 13:27:52 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "set_view.h"
#include "ft_printf.h"
#include "window_manipulation.h"
#include "fdf.h"

void		affiche_commandes(t_data *win)
{
	mlx_string_put(win->mlx_ptr, win->id_ptr, 20, 10, 65535, CMD_ROT_X);
	mlx_string_put(win->mlx_ptr, win->id_ptr, 20, 30, 65535, CMD_ROT_Y);
	mlx_string_put(win->mlx_ptr, win->id_ptr, 20, 50, 65535, CMD_ROT_Z);
	mlx_string_put(win->mlx_ptr, win->id_ptr, 20, 80, 65535, CMD_VIEW_ISO);
	mlx_string_put(win->mlx_ptr, win->id_ptr, 20, 100, 65535, CMD_VIEW_Z);
	mlx_string_put(win->mlx_ptr, win->id_ptr, 20, 120, 65535, CMD_VIEW_Y);
	mlx_string_put(win->mlx_ptr, win->id_ptr, 20, 140, 65535, CMD_VIEW_X);
	mlx_string_put(win->mlx_ptr, win->id_ptr, 20, 160, 65535, CMD_ZOOM_P);
	mlx_string_put(win->mlx_ptr, win->id_ptr, 20, 180, 65535, CMD_ZOOM_M);
	mlx_string_put(win->mlx_ptr, win->id_ptr, 20, 200, 65535, CMD_PEAK_MORE);
	mlx_string_put(win->mlx_ptr, win->id_ptr, 20, 220, 65535, CMD_PEAK_LESS);
	mlx_string_put(win->mlx_ptr, win->id_ptr, 20, 240, 65535, CMD_QUIT);
}

int			ft_binlog(int n)
{
	int		i;

	i = 1;
	while ((n /= 2))
		i++;
	return (i);
}

void		ft_init_window(t_data *win)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	if (!(win->pixel = (float***)malloc(sizeof(float**) * win->tab_height)))
		return ;
	while (i < win->tab_height)
	{
		j = 0;
		if (!(win->pixel[i] = (float**)malloc(sizeof(float*) * win->tab_width)))
			return ;
		while (j < win->tab_width)
		{
			if (!(win->pixel[i][j++] = (float*)malloc(sizeof(float) * 2)))
				return ;
		}
		i++;
	}
	ft_set_iso(win);
	if (!(win->mlx_ptr = mlx_init())
	|| !(win->id_ptr = mlx_new_window(win->mlx_ptr, FS_HEIGHT, FS_WIDTH, WIN)))
		return ;
	ft_init_zoom(win);
	ft_create_image(win);
	ft_loop(win);
}
