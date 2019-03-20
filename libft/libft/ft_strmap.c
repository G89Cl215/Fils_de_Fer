/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:49:40 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:39:15 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
