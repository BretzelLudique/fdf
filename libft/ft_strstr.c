/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:11:16 by ccarole           #+#    #+#             */
/*   Updated: 2019/04/15 17:41:38 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strctrl(const char *str, const char *find)
{
	int			i;
	int			j;
	int			ret;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] != find[j] && str[i] != '\0')
			i++;
		if (str[i] == find[j] && str[i] != '\0')
			ret = i;
		while (str[i] == find[j] && str[i] != '\0' && find[j] != '\0')
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

char			*ft_strstr(const char *str, const char *find)
{
	if (!find[0])
		return ((char*)str);
	else
		return ((char*)ft_strctrl(str, find));
}
