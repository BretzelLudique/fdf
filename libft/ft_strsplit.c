/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:09:47 by ccarole           #+#    #+#             */
/*   Updated: 2019/07/05 16:49:46 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_nbr_word(char const *s, char c)
{
	unsigned int		n;
	unsigned int		i;

	i = 0;
	n = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			n++;
		}
	}
	return (n);
}

char					**ft_strsplit(char const *s, char c)
{
	unsigned int		i;
	char				**tab;
	size_t				j;
	size_t				start;

	if (s == NULL)
		return (NULL);
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (ft_nbr_word(s, c) + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (i < ft_nbr_word(s, c) && s[j] != '\0')
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		start = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		tab[i] = ft_strsub(s, start, j - start);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
