/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:27:32 by flviret           #+#    #+#             */
/*   Updated: 2019/03/20 17:52:26 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft/libft/libft.h"
# include <math.h>
# include <unistd.h>
# include "libft/printf/ft_printf.h" 
#include <stdio.h>  // a supprimer tard

typedef struct	s_data
{
	int			x;
	int			y;
	int			height;
	int			width;
	int			peak_max;
	int			**tab;
	int			**(pixel[2]);
}				t_data;

int        open_error(char *file, t_data *data);
#endif
