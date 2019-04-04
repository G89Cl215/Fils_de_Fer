/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:51:44 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 15:57:12 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_uitoa_base(unsigned int nb, int base)
{
	char			*str;
	int				len;
	unsigned int	n;

	if (base <= 1 && base > 16)
		return (NULL);
	len = 1;
	n = nb;
	while ((n /= base) > 0)
		len++;
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = (nb % base > 9) ? (nb % base) + 55 : (nb % base) + 48;
		nb /= base;
	}
	return (str);
}
