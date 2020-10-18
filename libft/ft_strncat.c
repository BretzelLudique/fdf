/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:35:32 by ccarole           #+#    #+#             */
/*   Updated: 2019/04/12 18:06:59 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t len)
{
	size_t	j;
	size_t	n;

	j = ft_strlen(dest);
	n = 0;
	while ((src[n] != '\0') && (n < len))
	{
		dest[j] = src[n];
		j++;
		n++;
	}
	dest[j] = '\0';
	return (dest);
}
