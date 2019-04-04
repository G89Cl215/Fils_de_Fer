/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_viewtools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:14:06 by flviret           #+#    #+#             */
/*   Updated: 2019/04/03 14:18:52 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "set_view.h"

void		ft_set_view(t_data *data)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	while (i < data->tab_height)
	{
		j = 0;
		while (j < data->tab_width)
		{
			data->pixel[i][j][0] = (float)(i - data->tab_height / 2.0)
				* data->view[0][0]
				+ (float)(j - data->tab_width / 2.0) * data->view[0][1]
				+ data->depth_mod * (float)(data->tab[i][j]) * data->view[0][2];
			data->pixel[i][j][1] = (float)(i - data->tab_height / 2.0)
				* data->view[1][0]
				+ (float)(j - data->tab_width / 2.0) * data->view[1][1]
				+ data->depth_mod * (float)(data->tab[i][j]) * data->view[1][2];
			j++;
		}
		i++;
	}
}
