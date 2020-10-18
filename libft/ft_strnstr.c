/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:06:05 by ccarole           #+#    #+#             */
/*   Updated: 2019/04/29 19:09:49 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_ctrl(const char *str, const char *find, size_t l)
{
	size_t		i;
	size_t		j;
	size_t		ret;

	i = 0;
	while (str[i] != '\0' && i < l)
	{
		j = 0;
		while (str[i] != find[j] && str[i] && find[j])
			i++;
		if (str[i] == find[j] && str[i] != '\0')
			ret = i;
		while (str[i] == find[j] && i < l && str[i] != '\0' && find[j] != '\0')
		{
			i++;
			j++;
		}
		if (find[j] == '\0')
			return (&((char*)str)[ret]);
		if (str[i] == '\0')
			return (NULL);
		i = ret + 1;
	}
	return (NULL);
}

char			*ft_strnstr(const char *str, const char *find, size_t len)
{
	if (!find[0])
		return ((char*)str);
	else
		return ((char*)ft_ctrl(str, find, len));
}
