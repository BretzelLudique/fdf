/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:31:42 by ccarole           #+#    #+#             */
/*   Updated: 2019/04/29 19:10:06 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*cp_dest;
	char	*cp_src;

	cp_dest = (char*)dest;
	cp_src = (char*)src;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		cp_dest[i] = cp_src[i];
		if (cp_src[i] == (char)c)
			return (&cp_dest[i + 1]);
		i++;
	}
	return (NULL);
}
