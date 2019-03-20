/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:26:55 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:38:37 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*one_string_valid(const void *str, size_t size)
{
	char	*ptr;

	if (!(ptr = (char*)ft_memalloc(size)))
		return (NULL);
	ptr = (char*)ft_memcpy(ptr, str, size);
	return ((void*)ptr);
}

void		*ft_memjoin(const void *first, size_t size_f, const void *second,
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
	return ((void*)ptr);
}
