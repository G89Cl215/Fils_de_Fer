/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putullnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:52:28 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:39:34 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putullnbr_base(unsigned long long n, unsigned int base)
{
	if (base > 1 && base <= 16)
	{
		if (n >= base)
			putullnbr_base(n / base, base);
		(n % base) > 9 ? ft_putchar(n % base + 55) : ft_putchar(n % base + 48);
	}
}
