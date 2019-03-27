/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:21:59 by flviret           #+#    #+#             */
/*   Updated: 2019/03/27 16:34:48 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "window_manipulation.h"

void		*init_data(t_data *new)
{
	new->tab_height = 0;
	new->tab_width = 0;
	new->win_height = FS_HEIGHT;
	new->win_width = FS_WIDTH;
	new->offset_origin_x = FS_HEIGHT / 2; //arbitraire
	new->offset_origin_y = FS_WIDTH / 2; //arbitraire
	new->zoom =	4.0;
	return (new);
}

int		ft_parse_file(int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (++i < ac)
	{
		if (av[i][0] != '-' )
			j++;
	}
	if (j != 1)
	{
		j > 1 ? ft_printf("too many files found") : ft_printf("no file found");
		return (0);
	}
	return (1);
}

int            main(int ac, char **av)
{
	t_options        option;
	t_data            data;

	if (ac < 2)
		ft_printf("no file found");
	else if (ft_option(ac, av, &option))
	{
		if (!(ft_parse_file(ac, av)))
			return (0);
		init_data(&data);
		check_file(av[1], &data);
		new_tab(&data);
		fd_in_array(av[1], &data);
		ft_init_window(&data);
	}
	return (0);
}
