/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:49:24 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:39:13 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	if (!dst || !src)
		return (0);
	len = ft_strlen(src);
	if (size)
	{
		while (size-- > 1 && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (len);
}
