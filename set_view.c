/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:26:25 by tgouedar          #+#    #+#             */
/*   Updated: 2019/03/20 23:07:04 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "set_view.h"
#include "ft_printf.h"

const float		g_iso[2][3] =
{
	{-0.707106781186548, 0.707106781186548, 0.0},
	{0.408248290463863, 0.408248290463863, -0.816496580927726}
};

float			***ft_isometric_view(t_data *data)
{
	float	***pixel;
	int		i;
	int		j;

	i = 0;
	if (!(pixel = (float***)malloc(sizeof(float**) * data->height)))
		return (NULL);
	while (i < data->height)
	{
		j = 0;
		if (!(pixel[i] = (float**)malloc(sizeof(float*) * data->width)))
			return (NULL);
		while (j < data->width)
		{
			if (!(pixel[i][j] = (float*)malloc(sizeof(float) * 2)))
				return (NULL);
			pixel[i][j][0] = (float)(i) * g_iso[0][0] + (float)(j) * g_iso[0][1] + (float)(data->tab[i][j]) * g_iso[0][2];
			pixel[i][j][1] = (float)(i) * g_iso[1][0] + (float)(j) * g_iso[1][1] + (float)(data->tab[i][j]) * g_iso[1][2];
			ft_printf("pixel[%i, %i] = [%f, %f]\n", i, j, pixel[i][j][0], pixel[i][j][1]);
			j++;
		}
		i++;
	}
	ft_printf("fin calcul iso\n");
	return (pixel);
}
