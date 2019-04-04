/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:50:53 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 15:53:15 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	in_word;

	words = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			words++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (words);
}

static char		*ft_strcdup(char const *s, char c)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = 0;
	i = 0;
	while (s[len] && s[len] != c)
		len++;
	if (!(dup = (char*)malloc(sizeof(*dup) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	lentab;
	char	**tab;

	if (!s)
		return (NULL);
	i = 0;
	lentab = count_words(s, c);
	if (!(tab = (char**)malloc(sizeof(*tab) * (lentab + 1))))
		return (NULL);
	while (i < lentab)
	{
		while (*s == c)
			s++;
		if (!(tab[i] = ft_strcdup(s, c)))
		{
			ft_tabdel((void*)tab, i);
			return (0);
		}
		while (*s != c && *s)
			s++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
