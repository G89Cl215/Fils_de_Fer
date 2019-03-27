/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:18:11 by flviret           #+#    #+#             */
/*   Updated: 2019/03/27 17:41:09 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t        ft_arrlen(char **arr)
{
	size_t    i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

size_t			ft_intlen(long int n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while ((n /= 10))
		i++;
	return (i);
}

void			fd_in_array(char *file, t_data *data)
{
	unsigned int		x;
	int					nb;
	unsigned int		y;
	char				*line;
	int					fd;
	int					min;
	int					max;

	y = 0;
	x = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0 && y < data->tab_height)
	{
		x = 0;
		while (x < data->tab_width && *line)
		{
			if (ft_isdigit(*line))
			{
				nb = ft_atoi(line);
				max = nb < min ? nb : min;
				max = nb > max ? nb : max;
				data->tab[y][x] = nb;
				line += ft_intlen(nb);
				if (*line == ',')
					while (*line != ' ' && *line)
						line++;
				x++;
			}
			else
				line++;
		}
		y++;
	}
	data->tab_peak = max - min;
}

void			new_tab(t_data *data)
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

void            get_width(char *file, t_data *data)
{
	int				fd;
	int				c;
	char			*line;
	char			**tab;
	unsigned int	comp;

	c = 0;
	fd = open(file, O_RDONLY);
	if (get_next_line(fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		ft_strdel(&line);
		data->tab_width = ft_arrlen(tab);
		ft_free_tab(tab);
		while (get_next_line(fd, &line) > 0)
		{
			comp = 0;
			if ((line[c] != '\0'))
			{
				tab = ft_strsplit(line, ' ');
				ft_strdel(&line);
				comp = ft_arrlen(tab);
				ft_free_tab(tab);
				if (comp != (data->tab_width))
				{
					ft_printf("Width error");
					exit(EXIT_FAILURE);
				}
			}
		}
	}
	close(fd);
}

void			get_height(char *file, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_strdel(&line);
		(data->tab_height)++;
	}
	close(fd);
}

void        check_inside(char *file)
{
	int        fd;
	char    *line;

	fd = open(file, O_RDONLY);
	if (get_next_line(fd, &line) > 0)
	{
		if ((ft_isdigit(*line) == 0))
		{
			ft_printf("No Data Found");
			exit(EXIT_FAILURE);
		}
	}
	close(fd);
}

void        check_file(char *file, t_data *data)
{
	check_inside(file);
	get_height(file, data);
	error_height(data);
	get_width(file, data);
}
