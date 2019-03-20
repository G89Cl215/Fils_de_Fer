/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:57:04 by flviret           #+#    #+#             */
/*   Updated: 2018/11/30 12:02:31 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubfree(char *s, unsigned int start, size_t len)
{
	char *tmp;

	if (!(tmp = ft_strsub(s, start, len)))
		return (NULL);
	free(s);
	return (tmp);
}
