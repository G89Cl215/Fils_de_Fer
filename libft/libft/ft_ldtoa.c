/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:25:22 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:38:26 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*check_further(char *s, unsigned short precision, int *ret)
{
	int		i;
	int		max;

	max = precision + 3 + ((precision < 16) ? 16 - precision : 0);
	*ret = 0;
	i = precision + 1;
	if (s[i] >= '5' && i < max)
		*ret = 1;
	s[precision + 1] = '\0';
	return (s);
}

static char		*round_up(char *s, unsigned short precision, long l, int sign)
{
	int		ret;
	int		i;

	s = check_further(s, precision, &ret);
	i = precision;
	while (s[i] != '.' && ret)
	{
		if (s[i] < '9')
		{
			s[i] += 1;
			ret = 0;
		}
		else if (s[i] == '9')
		{
			s[i] = '0';
			ret = 1;
		}
		i--;
	}
	if (ret == 1)
		l += (sign == 1) ? -1 : 1;
	return (ft_ldtoa_concat(s, l, sign));
}

static char		*round_this(double d, long l, int sign)
{
	char	*whole;
	char	*tmp;

	whole = NULL;
	if ((d * 10.0) >= 5.0)
		l += (sign == 1) ? -1 : 1;
	if (sign)
	{
		if (!(whole = ft_lltoa_base(l, 10)))
			return (NULL);
		tmp = whole;
		if (!(whole = ft_strjoin("-", ft_lltoa_base(l, 10))))
		{
			ft_strdel(&tmp);
			return (NULL);
		}
		ft_strdel(&tmp);
	}
	else
	{
		if (!(whole = ft_lltoa_base(l, 10)))
			return (NULL);
	}
	return (whole);
}

/*
**	Precision + 3 :
**	1 for '.'
**	1 for up the precision by 1 (to round the number)
**	1 for '\0'
*/

static char		*fill_str(double d, unsigned short precision,
						long long whole, int sign)
{
	char			*s2;
	long long		l;
	unsigned short	p;
	char			*s;
	int				borne;

	borne = precision + 3 + ((precision < 16) ? 16 - precision : 0);
	s = NULL;
	if (precision <= 0)
		return (round_this(d, whole, sign));
	if (!(s2 = (char*)malloc(sizeof(*s2) * borne)))
		return (NULL);
	p = 0;
	s2[p++] = '.';
	while (p < borne)
	{
		d *= 10.0;
		l = (long long)d;
		s2[p++] = l + 48;
		d -= (long double)l;
	}
	s2[p] = '\0';
	s = round_up(s2, precision, whole, sign);
	return (s);
}

char			*ft_ldtoa(long double d, unsigned short precision)
{
	long long	l;
	char		*s;
	int			sign;

	sign = (d < 0) ? 1 : 0;
	d = (d < 0) ? -d : d;
	l = (long long)d;
	d -= (long double)l;
	s = fill_str(d, precision, l, sign);
	return (s);
}
