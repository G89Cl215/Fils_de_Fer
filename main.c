/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:21:59 by flviret           #+#    #+#             */
/*   Updated: 2019/03/20 23:19:22 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "window_manipulation.h"

size_t        ft_intlen(long int n)
{
	int i;

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

void            fd_in_array(char *file, t_data *data)
{
	int i;
	int x;
	int nb;
	int y;
	char *line;
	int fd;

	y = 0;
	i = 0;
	x = 0;
	printf("++++++++ tab in %s ++++++++++++++++\n", file);
	fd = open(file, O_RDONLY);
	printf("open ok\n");
	printf("line = %s\n", line);
	while (get_next_line(fd, &line) > 0 &&  y < data->height)
	{
		x= 0;
		printf("line = %s\n", line);
		while (x < data->width && *line)
		{
			if (ft_isdigit(*line))
			{
				nb = ft_atoi(line);
				data->tab[y][x] = nb;
				line += ft_intlen(nb);
				if (*line == ',')
					while (*line != ' ' && *line)
						line++;
				x++;
				printf("fill tab\n");
			}
		else
				line++;
		}
		printf("new_line\n");
		printf("llaaaaaaaa tab %d\n", (data->tab)[y][x - 1]);
		y++;
	}
}

void        new_tab(t_data *data)
{
	int    i;

	i = 0;
	if (!(data->tab = (int**)malloc(sizeof(int*) * (data->height))))
		return ;
	while (i < data->height)
	{
		if (!(data->tab[i] = (int*)malloc(sizeof(int) * data->width)))
			return ;
		i++;
	}
}


void     get_width(char *file, t_data *data)
{
	int fd;
	int c;
	char *line;

	c = 0;
	fd = open(file, O_RDONLY);
	if (get_next_line(fd, &line) > 0)
	{
		while ((line[c]))
		{
			while (line[c] == ' ')
				c++;
			if ((line[c]))
				(data->width)++;
			while (line[c] != ' ' && (line[c]))
				c++;
		}
		printf("largeur sa mere%d\n", data->width);
	}
	close (fd);
}

void     get_height(char *file, t_data *data)
{
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_strdel(&line);
		(data->height)++;
	}
	printf("hauteur sa mere %d\n", data->height);
	close (fd);
}


t_data	*init_data(void)
{
	t_data	*new;

	if (!(new = (t_data*)malloc(sizeof(*new))))
		return (NULL);

	new->x = 0;
	new->y = 0;
	new->height = 0;
	new->width = 0;
	new->peak_max = 0;
	return (new);
}


int main(int ac, char **av)
{
	t_data	data;
	t_win	win;
	char	*line;

	if (ac < 2)
		ft_printf("no file found");
	if (ac > 2)
		ft_printf("to file found");
	data = *(init_data());
	if (ac == 2)
	{
		open_error(av[1], &data);
		get_height(av[1], &data);
		get_width(av[1], &data);
		new_tab(&data);
		fd_in_array(av[1], &data);
		ft_init_window(&win, &data);
	}
	return (0);
}
