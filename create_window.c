/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:59:33 by tgouedar          #+#    #+#             */
/*   Updated: 2019/03/20 23:20:05 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "bresenham.h"
#include "set_view.h"
#include "ft_printf.h"
#include "window_manipulation.h"

int		ft_binlog(int n)
{
	int i;
	i = 1;
	while ((n /= 2))
		i++;
	return (i);
}

void	ft_init_window(t_win *win, t_data *data)
{
	int				max;
	void			*mlx_ptr;
	void			*win_ptr;

	win->pixel = ft_isometric_view(data);
	win->offset = 100;
	max = (data->height > data->width) ? data->height : data->width;
	win->factor = 100 / ft_binlog(max);
	ft_printf("map factor :%d\n", win->factor);
	ft_distortion_size_x(win, data->height, data->width);
	ft_distortion_size_y(win, data->height, data->width);
	ft_printf("les dimensions :%d, %d\n", win->width, win->height);
	win->mlx_ptr = mlx_init();
	win->id_ptr = mlx_new_window(win->mlx_ptr, win->height, win->width, "FdF");
	affiche_struct(win, data->height, data->width);
	ft_printf("Now looping\n");
	mlx_loop(win->mlx_ptr);
}
