/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:48:53 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 15:42:45 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sdup;
	size_t	len;

	len = ft_strlen(s);
	if (!(sdup = (char*)malloc(sizeof(*sdup) * (len + 1))))
		return (NULL);
	while (*s)
	{
		*sdup = *s;
		s++;
		sdup++;
	}
	*sdup = '\0';
	return (sdup - len);
}
