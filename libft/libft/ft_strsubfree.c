/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:57:04 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 15:54:14 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsubfree(char *s, unsigned int start, size_t len)
{
	char *tmp;

	if (!(tmp = ft_strsub(s, start, len)))
		return (NULL);
	free(s);
	return (tmp);
}
