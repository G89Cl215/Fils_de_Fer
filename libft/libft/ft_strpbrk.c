/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:50:41 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 15:51:53 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strpbrk(const char *s, const char *accept)
{
	char	*tmp;

	while (*accept)
	{
		if ((tmp = ft_strchr(s, *accept)))
			return (tmp);
		accept++;
	}
	return (NULL);
}
