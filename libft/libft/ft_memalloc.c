/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:26:16 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 15:32:49 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h> 

void	*ft_memalloc(size_t size)
{
	void	*block;

	if (!(block = (void*)malloc(sizeof(*block) * size)))
		return (NULL);
	ft_bzero(block, size);
	return (block);
}
