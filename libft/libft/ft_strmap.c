/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:49:40 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 15:47:19 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	size_t	len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (!(newstr = (char*)malloc(sizeof(*newstr) * (len + 1))))
		return (NULL);
	while (*s)
	{
		*newstr = f(*s);
		newstr++;
		s++;
	}
	*newstr = '\0';
	return (newstr - len);
}
