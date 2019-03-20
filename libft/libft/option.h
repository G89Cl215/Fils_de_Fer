/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:50:56 by tgouedar          #+#    #+#             */
/*   Updated: 2019/03/20 11:49:59 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTION_H
# define OPTION_H

# define OPT "Raglnort1"

typedef struct	s_options
{
	int			l : 1;
	int			r : 1;
	int			rec : 1;
	int			a : 1;
	int			t : 1;
	int			n : 1;
	int			e : 1;
	int			g : 1;
	int			o : 1;
}				t_options;

#endif
