/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:18:11 by flviret           #+#    #+#             */
/*   Updated: 2019/04/03 13:58:02 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			check_width(int fd, int width)
{
	char		*line;
	int			comp;
	char		**tab;

	while (get_next_line(fd, &line) > 0)
	{
		comp = 0;
		if ((line[0]))
		{
			tab = ft_strsplit(line, ' ');
			ft_strdel(&line);
			comp = ft_arrlen(tab);
			ft_free_tab(tab);
			if (comp < (width))
			{
				ft_printf("Width error");
				exit(EXIT_FAILURE);
			}
		}
	}
}

void			get_width(char *file, t_data *data)
{
	int				fd;
	char			*line;
	char			**tab;

	fd = open(file, O_RDONLY);
	if (get_next_line(fd, &line) > 0)
	{
		if (!(tab = ft_strsplit(line, ' ')))
		{
			ft_strdel(&line);
			return ;
		}
		ft_strdel(&line);
		data->tab_width = ft_arrlen(tab);
		ft_free_tab(tab);
		check_width(fd, data->tab_width);
		ft_strdel(&line);
	}
	free(line);
	close(fd);
}

void			get_height(char *file, t_data *data)
{
	int			fd;
	char		*line;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_strdel(&line);
		(data->tab_height)++;
	}
	ft_strdel(&line);
	close(fd);
}

int				check_inside(char *file)
{
	int		fd;
	char	*line;

	if (!(fd = safe_open(file)))
		return (0);
	if (get_next_line(fd, &line) > 0)
	{
		if (!(ft_isdigit(*line)))
		{
			ft_printf("No Data Found");
			exit(EXIT_FAILURE);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	return (1);
}

int				check_file(char *file, t_data *data)
{
	if (!(check_inside(file)))
		return (0);
	get_height(file, data);
	error_height(data);
	get_width(file, data);
	return (1);
}
