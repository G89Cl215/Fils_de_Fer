/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_ten.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:27:15 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:38:41 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow_ten(double nb, int power)
{
	int		count;

	count = 0;
	if (power < 0)
		return (0);
	while (count < power)
	{
		nb *= 10;
		count++;
	}
	return (nb);
}
