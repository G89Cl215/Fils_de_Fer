/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:49:15 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:39:11 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	This function takes 2 malloc'ed strings.
**	It will make a strjoin with them and free them.
*/

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new;

	if (!(new = ft_strjoin(s1, s2)))
		return (NULL);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (new);
}
