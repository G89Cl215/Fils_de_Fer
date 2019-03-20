/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:26:21 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:38:33 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;

	c = (unsigned char)c;
	pdest = (unsigned char*)dest;
	psrc = (const unsigned char*)src;
	while (n--)
	{
		*pdest = *psrc;
		if (*psrc == (unsigned char)c)
			return (pdest + 1);
		pdest++;
		psrc++;
	}
	return (NULL);
}
