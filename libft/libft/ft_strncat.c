/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:49:56 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:39:17 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*iter;

	iter = dest;
	while (*iter)
		iter++;
	while (n-- > 0 && *src)
	{
		*iter = *src;
		iter++;
		src++;
	}
	*iter = '\0';
	return (dest);
}
