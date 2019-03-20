/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:50:36 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:39:22 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = 0;
	if (0 == (len = ft_strlen(s2)))
		return ((char*)s1);
	if (len > ft_strlen(s1) || len > n)
		return (0);
	while (*s1 && (n - (len - 1)) > 0)
	{
		if (*s1 == *s2)
			if (!ft_strncmp(s1, s2, len))
				return ((char*)s1);
		s1++;
		n--;
	}
	return (0);
}
