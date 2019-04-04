/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loopandevent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:03:43 by tgouedar          #+#    #+#             */
/*   Updated: 2019/04/04 12:31:51 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "set_view.h"
#include "window_manipulation.h"

void		ft_relevant_key(t_data *win, int key_id)
{
	if (key_id == 24 || key_id == 27)
		ft_set_view(win);
	if (key_id == 0 || key_id == 1 || key_id == 2 || key_id == 12
	|| key_id == 13 || key_id == 14 || key_id == 24 || key_id == 27
	|| key_id == 34 || key_id == 37 || key_id == 38 || key_id == 40
	|| key_id == 123 || key_id == 124 || key_id == 125 || key_id == 126
	|| key_id == 69 || key_id == 78)
		ft_create_image(win);
}

void		key_suit(int key_id, t_data *win)
{
	if (key_id == 78)
		win->zoom *= 0.8;
	if (key_id == 69)
		win->zoom *= 1.25;
	if (key_id == 34)
	{
		ft_set_iso(win);
		ft_init_zoom(win);
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
}

void		key_suit2(int key_id, t_data *win)
{
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
	if (key_id == 24)
		win->depth_mod *= 1.25;
	if (key_id == 27)
		win->depth_mod *= 0.8;
}

int			key_trigger(int key_id, void *param)
{
	t_data	*win;

	win = (t_data*)param;
	key_suit(key_id, win);
	key_suit2(key_id, win);
	ft_relevant_key(win, key_id);
	return (0);
}

void		ft_loop(t_data *win)
{
	mlx_key_hook(win->id_ptr, key_trigger, (void *)win);
	mlx_loop(win->mlx_ptr);
}
