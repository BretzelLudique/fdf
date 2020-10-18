/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:03:51 by ccarole           #+#    #+#             */
/*   Updated: 2019/04/25 18:19:28 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*new;
	int		k;

	k = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	j--;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	if (!(new = (char*)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	while (s[i] != '\0' && i <= j)
	{
		new[k++] = s[i++];
	}
	new[k] = '\0';
	return (new);
}
