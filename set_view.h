/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_view.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:26:31 by tgouedar          #+#    #+#             */
/*   Updated: 2019/03/25 19:36:12 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_VIEW_H
# define SET_VIEW_H

# include "fdf.h"

void		ft_set_iso(t_data *data);
void		ft_rot(t_data *data, int axis, int direct);
void		ft_set_view(t_data *data);

#endif
