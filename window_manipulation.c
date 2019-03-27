/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:39:54 by tgouedar          #+#    #+#             */
/*   Updated: 2019/03/27 17:27:30 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_manipulation.h"

static float	ft_find_dim(t_data *win, int flag, int redef_origin)
{
	unsigned int		i;
	unsigned int		j;
	float				max;
	float				min;

//	ft_printf("%i, %i", height, width);
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
/*	if ((redef_origin))
		(win->origin)[flag] = min;*/
	return (max - min);
}

void		ft_free_pixel_tab(t_data *win)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	while (i < win->tab_height)
	{
		j = 0;
		while (j < win->tab_width)
		{
			printf("\n%i / %i\n", i, j);
			free(win->pixel[i][j++]);
		}
		free(win->pixel[i]);
		i++;
	}
	free(win->pixel);
//			printf("\n%i / %i\n", i, j);
}
