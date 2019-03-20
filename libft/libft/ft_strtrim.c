/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:51:07 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:39:27 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*trimmed;
	char const	*first;
	char const	*last;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (*s == '\0')
		return (ft_strdup(""));
	first = s;
	while (*s)
	{
		if (*s != ' ' && *s != '\n' && *s != '\t')
			last = s;
		s++;
	}
	trimmed = ft_strndup(first, (last - first) + 1);
	return (trimmed);
}
