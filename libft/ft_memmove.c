/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:00:09 by ccarole           #+#    #+#             */
/*   Updated: 2019/04/29 15:43:35 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pt_src;
	char	*pt_dst;

	pt_src = (char*)src;
	pt_dst = (char*)dst;
	if (pt_dst >= pt_src)
	{
		pt_src = pt_src + len - 1;
		pt_dst = pt_dst + len - 1;
		while (len > 0)
		{
			*pt_dst-- = *pt_src--;
			len--;
		}
	}
	if (pt_dst < pt_src)
	{
		while (len > 0)
		{
			*pt_dst++ = *pt_src++;
			len--;
		}
	}
	return ((char*)dst);
}
