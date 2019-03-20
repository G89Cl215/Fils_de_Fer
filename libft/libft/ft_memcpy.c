/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:26:41 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:38:36 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	char		*pstr1;
	char const	*pstr2;

	pstr1 = (char*)str1;
	pstr2 = (const char*)str2;
	while (n--)
		*pstr1++ = *pstr2++;
	return (str1);
}
