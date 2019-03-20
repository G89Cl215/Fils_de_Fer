/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlnbr_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:52:18 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:39:33 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putlnbr_base(long n, short base)
{
	if (base > 1 && base <= 16)
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= base)
			putlnbr_base(n / base, base);
		(n % base) > 9 ? ft_putchar(n % base + 55) : ft_putchar(n % base + 48);
	}
}
