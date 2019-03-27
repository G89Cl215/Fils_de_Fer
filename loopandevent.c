/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loopandevent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:03:43 by tgouedar          #+#    #+#             */
/*   Updated: 2019/03/27 16:36:52 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "fdf.h"
#include "set_view.h"
#include "window_manipulation.h"

void		ft_relevant_key(t_data *win, int key_id)
{
	if (key_id == 0 || key_id == 1 || key_id == 2 || key_id == 12
	|| key_id == 13 || key_id == 14 || key_id == 34 || key_id == 37
	|| key_id == 38 || key_id == 40 || key_id == 123 || key_id == 124
   	|| key_id == 125 || key_id == 126)
		ft_create_image(win);
}

int		key_trigger(int key_id, void *param)
{
	t_data	*win;
	int		min;
	int		max;

	win = (t_data*)param;
	min = win->win_height > win->win_width ? win->win_width : win->win_height;
	max = win->win_height < win->win_width ? win->win_width : win->win_height;
	printf("key_id : %i\n", key_id);
	if (key_id == 124)
		win->offset_origin_x += 20.0;
	if (key_id == 125)
		win->offset_origin_y += 20.0;
	if (key_id == 123)
		win->offset_origin_x -= 20.0;
	if (key_id == 126)
		win->offset_origin_y -= 20.0;
	if (key_id == 0)
		ft_rot(win, 2, -1);
	if (key_id == 1)
		ft_rot(win, 1, -1);
	if (key_id == 2)
		ft_rot(win, 0, -1);
	if (key_id == 12)
		ft_rot(win, 2, 1);
	if (key_id == 13)
		ft_rot(win, 1, 1);
	if (key_id == 14)
		ft_rot(win, 0, 1);
	if (key_id == 34)
	{
		ft_set_iso(win);
		win->offset_origin_x = FS_HEIGHT / 2;
		win->offset_origin_y = FS_WIDTH / 2;
		win->zoom = 4.0;
	}
	if (key_id == 38)
		ft_view_from_axis(win, 0);
	if (key_id == 40)
		ft_view_from_axis(win, 1);
	if (key_id == 37)
		ft_view_from_axis(win, 2);
	if (key_id == 53)
	{
		ft_free_pixel_tab(win);
		mlx_destroy_image(win, (void*)(win->im_data));
		mlx_clear_window(win, (void*)(win->id_ptr));
		mlx_destroy_window(win, (void*)(win->id_ptr));
		exit(EXIT_SUCCESS);
	}
	ft_relevant_key(win, key_id);
	return (0);
}

int		mouse_trigger(int key_id, int x, int y, void *param)
{
	t_data	*win;
	int		min;

	win = (t_data*)param;
	min = win->win_height > win->win_width ? win->win_width : win->win_height;
	if (key_id == 4)
	{
		win->zoom /= 2;
		ft_create_image(win);
	}
	if (key_id == 5)
	{
		win->zoom *= 2;
		ft_create_image(win);
	}
	return (0);
}

void	ft_loop(t_data *win)
{
	mlx_key_hook(win->id_ptr, key_trigger, (void *)win);
	mlx_mouse_hook(win->id_ptr, mouse_trigger, (void *)win);
	mlx_loop(win->mlx_ptr);
}
