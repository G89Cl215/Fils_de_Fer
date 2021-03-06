/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:27:32 by flviret           #+#    #+#             */
/*   Updated: 2019/04/06 13:52:34 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stddef.h> 

typedef struct	s_array
{
	unsigned int	x;
	unsigned int	y;
	int				min;
	int				max;
	int				nb;
}				t_array;

typedef struct	s_data
{
	void			*mlx_ptr;
	void			*id_ptr;
	char			*im_data;
	int				color;
	float			origin[2];
	int				offset_origin_x;
	int				offset_origin_y;
	float			view[2][3];
	unsigned int	win_width;
	unsigned int	win_height;
	float			zoom;
	float			depth_mod;
	float			***pixel;
	int				**tab;
	unsigned int	tab_width;
	unsigned int	tab_height;
	unsigned int	tab_peak;
}				t_data;

int				open_error(int ac, char **av);
size_t			ft_intlen(long int n);
void			fd_in_array(char *file, t_data *data);
void			new_tab(t_data *data);
void			error_height(t_data *data);
int				check_file(char *file, t_data *data);
void			ft_free_tab(char **tab);
int				safe_open(const char *pathname);
#endif
