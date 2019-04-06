/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:21:59 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 17:30:01 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "window_manipulation.h"

static void	*init_data(t_data *new)
{
	new->tab_height = 0;
	new->color = 0;
	new->tab_width = 0;
	new->win_height = FS_HEIGHT;
	new->win_width = FS_WIDTH;
	new->offset_origin_x = FS_HEIGHT / 2;
	new->offset_origin_y = FS_WIDTH / 2;
	new->depth_mod = 1.0;
	return (new);
}

static int	ft_parse_file(int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (++i < ac)
	{
		if (av[i][0] != '-')
			j++;
	}
	if (j != 1)
	{
		j > 1 ? ft_printf("Too many files found") : ft_printf("No file found");
		return (0);
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_data			data;

	if (!(ft_parse_file(ac, av)))
		return (0);
	init_data(&data);
	if (!(check_file(av[1], &data)))
		return (0);
	new_tab(&data);
	fd_in_array(av[1], &data);
	ft_init_window(&data);
	return (0);
}
