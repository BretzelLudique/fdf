/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:28:53 by ccarole           #+#    #+#             */
/*   Updated: 2019/06/06 22:24:25 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		slen;

	slen = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = ft_strnew(slen)))
		return (NULL);
	if (s1)
		ft_strcpy(new, s1);
	if (s2)
		ft_strcat(new, s2);
	return (new);
}
