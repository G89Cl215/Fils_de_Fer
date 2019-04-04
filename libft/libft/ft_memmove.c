/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:27:05 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 16:03:38 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	pdst = (unsigned char*)dst;
	psrc = (const unsigned char*)src;
	if (dst == src || !n)
		return (dst);
	if (src > dst)
		while (n--)
			*pdst++ = *psrc++;
	else
		while (n--)
			pdst[n] = psrc[n];
	return (dst);
}
