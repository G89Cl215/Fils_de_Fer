/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:27:48 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:38:44 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_decimal_part(char *s, unsigned short p)
{
	unsigned short	ret;
	unsigned short	ind;

	s[p] = '\0';
	ret = 1;
	while (1)
	{
		ind = p - (ret + 1);
		if (s[p - ret] >= '5')
		{
			if (s[ind] + 1 != 58)
			{
				s[ind] += 1;
				break ;
			}
			else if (s[ind] + 1 == 58)
				s[ind] = '0';
			ret++;
		}
		else
			break ;
	}
	s[p - 1] = '\0';
	ft_putstr(s);
	ft_strdel(&s);
}

void			ft_putdouble(double d, unsigned short precision)
{
	long			l;
	unsigned short	p;
	char			*s;

	if ((s = (char*)malloc(sizeof(*s) * (precision + 2))))
	{
		if (d < 0)
			ft_putchar('-');
		l = (long)d;
		putlnbr_base(l, 10);
		d -= l;
		if (precision > 0)
		{
			ft_putchar('.');
			p = 0;
			while (p < precision + 1)
			{
				d *= 10;
				l = (long)d;
				s[p++] = l + 48;
				d -= l;
			}
			print_decimal_part(s, p);
		}
	}
}
