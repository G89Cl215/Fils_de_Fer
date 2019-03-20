/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:50:08 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:39:18 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*str;

	str = dest;
	while (*src && n > 0)
	{
		*str++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*str++ = '\0';
		n--;
	}
	return (dest);
}
