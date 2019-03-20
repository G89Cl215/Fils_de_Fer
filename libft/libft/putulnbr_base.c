/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putulnbr_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:52:31 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:39:35 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putulnbr_base(unsigned long n, unsigned int base)
{
	if (base > 1 && base <= 16)
	{
		if (n >= base)
			putulnbr_base(n / base, base);
		(n % base) > 9 ? ft_putchar(n % base + 55) : ft_putchar(n % base + 48);
	}
}
