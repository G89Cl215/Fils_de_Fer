/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:26:16 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:38:33 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*block;

	if (!(block = (void*)malloc(sizeof(*block) * size)))
		return (NULL);
	ft_bzero(block, size);
	return (block);
}
