/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:28:57 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:38:52 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_lowercase(const char *str)
{
	while (*str)
	{
		if (!ft_islower(*str))
			return (0);
		str++;
	}
	return (1);
}
