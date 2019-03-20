/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:51:19 by flviret           #+#    #+#             */
/*   Updated: 2019/03/20 23:08:42 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		open_error(char *file, t_data *data)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_printf("no file.");
		ft_putendl(file);
		exit(EXIT_FAILURE);
	}
	if ((read(fd, 0, 0) < 0))
	{
		ft_printf("no data inside.");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return (1);
}

int		error_height(char *file, t_data *data)
{
	if (data->height == 0)
	{
		ft_printf("no data inside");
		exit(EXIT_FAILURE);
	}
	return (1);
}
