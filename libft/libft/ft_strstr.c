/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:50:58 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:39:26 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	len;

	len = ft_strlen(s2);
	if (!*s2)
		return ((char*)s1);
	while (*s1)
	{
		if (*s1 == *s2)
			if (!ft_strncmp(s1, s2, len))
				return ((char*)s1);
		s1++;
	}
	return (0);
}
