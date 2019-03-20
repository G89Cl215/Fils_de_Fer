/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:50:45 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:39:23 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*rchr;

	rchr = NULL;
	while (*s)
	{
		if (*s == c)
			rchr = s;
		s++;
	}
	if (*s == c)
		return ((char*)s);
	return ((char*)rchr);
}
