/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:27:00 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 15:34:48 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*one_string_valid(void *str, size_t size)
{
	char	*ptr;

	if (!(ptr = (char*)ft_memalloc(size)))
		return (NULL);
	ptr = (char*)ft_memcpy(ptr, str, size);
	ft_memdel(&str);
	return ((void*)ptr);
}

/*
**	This function is supposed to be used with 2 malloc'ed strings in params
*/

void		*ft_memjoin_free(void *first, size_t size_f, void *second,
				size_t size_s)
{
	char	*ptr;
	char	*ptr2;

	if (first == NULL && second == NULL)
		return (NULL);
	if (first != NULL && second == NULL)
		return (one_string_valid(first, size_f));
	if (first == NULL && second != NULL)
		return (one_string_valid(second, size_s));
	if (!(ptr = (char*)ft_memalloc(size_f + size_s)))
		return (NULL);
	ptr = (char*)ft_memcpy(ptr, first, size_f);
	ptr2 = ptr + size_f;
	ptr2 = (char*)ft_memcpy(ptr2, second, size_s);
	ft_memdel(&first);
	ft_memdel(&second);
	return ((void*)ptr);
}
