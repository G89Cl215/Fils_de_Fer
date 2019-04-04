/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:28:40 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 15:40:09 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 

int		*ft_range(int start, int end)
{
	int		*tab;
	int		i;

	if (end < start)
		return (NULL);
	if (!(tab = (int*)malloc(sizeof(*tab) * (end - start))))
		return (NULL);
	i = 0;
	while (start <= end)
		tab[i++] = start++;
	return (tab);
}
