/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:39:54 by tgouedar          #+#    #+#             */
/*   Updated: 2019/03/20 22:58:55 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_manipulation.h"

static float	ft_find_dim(t_win *win, int height, int width, int flag)
{
	int		i;
	int		j;
	float	max;
	float	min;

	i = 0;
	max = (win->pixel)[0][0][flag];
	min = (win->pixel)[0][0][flag];
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if ((win->pixel)[i][j][flag] > max)
				max = (win->pixel)[i][j][flag];
			if ((win->pixel)[i][j][flag] < min)
				min = (win->pixel)[i][j][flag];
			j++;
		}
		i++;
	}
	(win->origin)[flag] = min;
	return (max - min);
}

void			ft_distortion_size_x(t_win *win, int height, int width)
{
	win->height = ft_find_dim(win, height, width, 0) * win->factor + 2 * win->offset;
	if ((win->height))
		win->def_x = win->factor * (float)(win->height - 0.5 * win->offset) / win->height;
	(win->origin)[0] *= win->def_x;
}

void			ft_distortion_size_y(t_win *win, int width, int height)
{
	win->width = ft_find_dim(win, width, height, 1) * win->factor + 2 * win->offset;
	ft_printf("%d", win->width);
	if ((win->width))
		win->def_y = win->factor * (float)(win->width - 0.5 * win->offset) / win->width;
	(win->origin)[1] *= win->def_y;
}
