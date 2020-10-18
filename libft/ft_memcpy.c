/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:29:42 by ccarole           #+#    #+#             */
/*   Updated: 2019/04/29 18:49:57 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*cp_dest;
	char		*cp_src;

	cp_dest = (char*)dst;
	cp_src = (char*)src;
	i = 0;
	if (src <= dst)
		ft_memmove(dst, src, n);
	else
		while (i < n)
		{
			cp_dest[i] = cp_src[i];
			i++;
		}
	return (cp_dest);
}
