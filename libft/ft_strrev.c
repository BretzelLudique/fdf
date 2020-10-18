/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:35:46 by ccarole           #+#    #+#             */
/*   Updated: 2019/04/25 20:42:04 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrev(char *s)
{
	unsigned int	i;
	unsigned int	j;
	char			tmp;

	i = 0;
	j = ft_strlen(s) - 1;
	if (s == NULL)
		return (NULL);
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
	return (s);
}
