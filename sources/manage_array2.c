/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_array2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:57:30 by flviret           #+#    #+#             */
/*   Updated: 2019/04/06 13:38:27 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "fdf.h"
#include "libft.h"

void		ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

static void	ft_in_array2(t_array *array, char **line, t_data *data)
{
	array->x = 0;
	while (array->x < data->tab_width && **line)
	{
		if (ft_isdigit(**line))
		{
			array->nb = ft_atoi(*line);
			array->max = array->nb < array->min ? array->nb : array->min;
			array->max = array->nb > array->max ? array->nb : array->max;
			data->tab[array->y][array->x] = array->nb;
			*line += ft_intlen(array->nb);
			if (**line == ',')
				while (**line != ' ' && **line)
					(*line)++;
			(array->x)++;
		}
		else
			(*line)++;
	}
	(array->y)++;
}

void		fd_in_array(char *file, t_data *data)
{
	t_array				array;
	char				*line;
	int					fd;
	char				*tmp;

	ft_bzero(&array, sizeof(array));
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0 && array.y < data->tab_height)
	{
		tmp = line;
		ft_in_array2(&array, &line, data);
		ft_strdel(&tmp);
	}
	data->tab_peak = array.max - array.min;
}

void		new_tab(t_data *data)
{
	unsigned int		i;

	i = 0;
	if (!(data->tab = (int**)malloc(sizeof(int*) * (data->tab_height))))
		return ;
	while (i < data->tab_height)
	{
		if (!(data->tab[i] = (int*)malloc(sizeof(int) * data->tab_width)))
			return ;
		i++;
	}
}
