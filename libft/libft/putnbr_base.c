/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:52:23 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:39:34 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putnbr_base(int n, int base)
{
	if (base > 1 && base <= 16)
	{
		if (n == -2147483648)
		{
			n = 147483648;
			ft_putstr("-2");
		}
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= base)
			putnbr_base(n / base, base);
		(n % base) > 9 ? ft_putchar(n % base + 55) : ft_putchar(n % base + 48);
	}
}
