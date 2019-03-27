/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manipulation.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:45:47 by tgouedar          #+#    #+#             */
/*   Updated: 2019/03/27 17:39:28 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_MAINPULATION_H
# define WINDOW_MAINPULATION_H

# include "fdf.h"
#include "libft/libft/option.h"

# define DEF_OFFSET 250
# define WIN_FACTOR 50
# define FS_WIDTH 1395
# define FS_HEIGHT 2560
# define CMD_ROT_X "Rotations   : autour de l'axe x < e, d > "
# define CMD_ROT_Y "              autour de l'axe y < w, s > "
# define CMD_ROT_Z "              autour de l'axe z < q, a > "
# define CMD_VIEW_ISO "Vues        : isometrique < i > "
# define CMD_VIEW_Z "              selon l'axe z < l > "
# define CMD_VIEW_Y "              selon l'axe y < k > "
# define CMD_VIEW_X "              selon l'axe x < j > "

void				ft_init_window(t_data *data);
void				ft_create_image(t_data *win); 
void				ft_loop(t_data *win);
void				ft_view_from_axis(t_data *win, int axis);
void				ft_free_pixel_tab(t_data *win);
void				affiche_commandes(t_data *win);

#endif
