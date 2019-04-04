/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:25:29 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 15:31:11 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h> 

char	*ft_lltoa_base(long long nb, short base)
{
	char		*str;
	int			len;
	int			sign;
	long long	n;

	if (base <= 1 && base > 16)
		return (NULL);
	if (nb < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	sign = (nb < 0 ? 1 : 0);
	len = sign + 1;
	nb = (sign == 1 ? -nb : nb);
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
	(sign == 1) ? str[0] = '-' : 0;
	return (str);
}
