/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:26:25 by tgouedar          #+#    #+#             */
/*   Updated: 2019/03/27 15:25:53 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "set_view.h"
#include "libft/printf/ft_printf.h"

const float		g_iso[2][3] =
{
	{-0.707106781186548, 0.707106781186548, 0.0},
	{0.408248290463863, 0.408248290463863, -0.816496580927726}
};

const float		g_cos_rot =	0.99144486137381;
const float		g_sin_rot = 0.130526192220052;

void			ft_set_iso(t_data *data)
{
	data->view[0][0] = g_iso[0][0];
	data->view[0][1] = g_iso[0][1];
	data->view[0][2] = g_iso[0][2];
	data->view[1][0] = g_iso[1][0];
	data->view[1][1] = g_iso[1][1];
	data->view[1][2] = g_iso[1][2];
	ft_set_view(data);
}

static void			ft_fill_rot(float *coeff, int flag, int direct)
{
	if (flag == 0 || flag == 3)
		*coeff = g_cos_rot;
	else if (flag == 1)
		*coeff = (float)(-1.0 * direct * g_sin_rot);
	else if (flag == 2)
		*coeff = (float)(direct * g_sin_rot);
}

static void			ft_apply_rot(t_data *data, float rot[3][3])
{
	int		i;
	float	tmp[2][3];

	i = 0;
	while (i < 3)
	{
		tmp[0][i] = rot[0][i] * data->view[0][0] + rot[1][i] * data->view[0][1]
			+ rot[2][i] * data->view[0][2];
		tmp[1][i] = rot[0][i] * data->view[1][0] + rot[1][i] * data->view[1][1]
			+ rot[2][i] * data->view[1][2];
		i++;
	}
	data->view[0][0] = tmp[0][0];
	data->view[0][1] = tmp[0][1];
	data->view[0][2] = tmp[0][2];
	data->view[1][0] = tmp[1][0];
	data->view[1][1] = tmp[1][1];
	data->view[1][2] = tmp[1][2];
}

void			ft_rot(t_data *data, int axis, int direct)
{
	int		i;
	int		j;
	int		flag;
	float	rot[3][3];

	i = 0;
	flag = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (j == axis && i == axis)
				rot[i][j++] = 1.0;
			else if (j == axis || i == axis)
				rot[i][j++] = 0.0;
			else
				ft_fill_rot(&(rot[i][j++]), flag++, direct);
		}
		printf("%f,\t%f,\t%f\n", rot[i][0], rot[i][1], rot[i][2]);
		i++;
	}
	ft_apply_rot(data, rot);
	ft_set_view(data);
}

void			ft_view_from_axis(t_data *data, int axis)
{
	int			i;
	float		j;

	i = 0;
	j = 0.0;
	data->view[0][axis] = 0.0;
	data->view[1][axis] = 0.0;
	while (i < 3)
	{
		if ((i - axis))
		{
			data->view[1][i] = j;
			data->view[0][i] = -1.0 + j;
			j += 1.0;
		}
		i++;
	}
	ft_set_view(data);
}

void			ft_set_view(t_data *data)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	while (i < data->tab_height)
	{
		j = 0;
		while (j < data->tab_width)
		{
			data->pixel[i][j][0] = (float)(i - data->tab_height / 2.0) * data->view[0][0]
			+ (float)(j - data->tab_width / 2.0) * data->view[0][1]
			+ (float)(data->tab[i][j]) * data->view[0][2];
			data->pixel[i][j][1] = (float)(i - data->tab_height / 2.0) * data->view[1][0]
			+ (float)(j - data->tab_width / 2.0) * data->view[1][1]
			+ (float)(data->tab[i][j]) * data->view[1][2];
//			ft_printf("data->pixel[%i, %i] = [%f, %f]\n", i, j, data->pixel[i][j][0], data->pixel[i][j][1]);
			j++;
		}
		i++;
	}
	ft_printf("fin calcul iso\n");
}
