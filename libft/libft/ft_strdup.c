/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:48:53 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:39:07 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sdup;
	size_t	len;

	len = ft_strlen(s);
	if (!(sdup = (char*)malloc(sizeof(*sdup) * (len + 1))))
		return (0);
	while (*s)
	{
		*sdup = *s;
		s++;
		sdup++;
	}
	*sdup = '\0';
	return (sdup - len);
}
