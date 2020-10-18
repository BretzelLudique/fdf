/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 21:13:56 by ccarole           #+#    #+#             */
/*   Updated: 2019/04/29 15:46:26 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	n;

	n = 0;
	while ((src[n] != '\0') && (n < len))
	{
		dest[n] = src[n];
		n++;
	}
	while (n < len)
	{
		dest[n] = '\0';
		n++;
	}
	return (dest);
}
