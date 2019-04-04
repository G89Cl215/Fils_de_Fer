/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_safe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:50:14 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 15:49:41 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy_safe(char *dest, const char *src, size_t n)
{
	if (n > 0)
	{
		dest = ft_strncpy(dest, src, n - 1);
		dest[n - 1] = '\0';
	}
	return (dest);
}
