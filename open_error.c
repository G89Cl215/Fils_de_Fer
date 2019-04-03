/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:51:19 by flviret           #+#    #+#             */
/*   Updated: 2019/04/03 13:40:51 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		open_error(int ac, char **av)
{
	int		fd;
	int		i;

	i = 1;
	while (i < ac && av[i][0] == '-')
		i++;
	if ((fd = open(av[i], O_RDONLY)) <= 0)
	{
		ft_printf("no file.");
		ft_putendl(av[i]);
		exit(EXIT_FAILURE);
	}
	if ((read(fd, 0, 0) < 0))
	{
		ft_printf("no data inside.");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return (i);
}

void	error_height(t_data *data)
{
	if (data->tab_height == 0)
	{
		ft_printf("no data inside");
		exit(EXIT_FAILURE);
	}
}

int		safe_open(const char *pathname)
{
	int		fd;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("No File Found");
		return (0);
	}
	return (fd);
}
