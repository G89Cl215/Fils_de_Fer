/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_concat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:23:17 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:38:07 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa_concat(char *s, long l, int sign)
{
	char	*whole;
	char	*tmp;

	whole = NULL;
	if (sign)
	{
		if (!(whole = ft_ltoa_base(l, 10)))
			return (NULL);
		tmp = whole;
		if (!(whole = ft_strjoin("-", whole)))
		{
			ft_strdel(&tmp);
			return (NULL);
		}
	}
	if (!(s = ft_strjoin_free((whole) ? whole : ft_ltoa_base(l, 10), s)))
		return (NULL);
	return (s);
}

char	*ft_ldtoa_concat(char *s, long long l, int sign)
{
	char	*whole;
	char	*tmp;

	whole = NULL;
	if (sign)
	{
		if (!(whole = ft_ltoa_base(l, 10)))
			return (NULL);
		tmp = whole;
		if (!(whole = ft_strjoin("-", whole)))
		{
			ft_strdel(&tmp);
			return (NULL);
		}
	}
	if (!(s = ft_strjoin_free((whole) ? whole : ft_ltoa_base(l, 10), s)))
		return (NULL);
	return (s);
}
