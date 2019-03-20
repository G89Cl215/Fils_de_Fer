/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manipulation.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:45:47 by tgouedar          #+#    #+#             */
/*   Updated: 2019/03/20 22:59:34 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_MAINPULATION_H
# define WINDOW_MAINPULATION_H

# include "fdf.h"

# define DEF_OFFSET 250
# define WIN_FACTOR 50

typedef struct		s_win
{
	void				*mlx_ptr;
	void				*id_ptr;
	float				origin[2];
	unsigned int		offset;
	unsigned int		factor;
	unsigned int		width;
	unsigned int		height;
	float				def_x;
	float				def_y;
	float				***pixel;
}					t_win;

void	ft_distortion_size_x(t_win *win, int height, int width);
void	ft_distortion_size_y(t_win *win, int height, int width);
void	ft_init_window(t_win *win, t_data *data);

#endif
