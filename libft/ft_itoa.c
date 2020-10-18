/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:14:07 by ccarole           #+#    #+#             */
/*   Updated: 2019/04/25 18:11:40 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_len(int n)
{
	unsigned int	len;
	unsigned int	nb;

	nb = n;
	len = 0;
	if (n < 0)
	{
		nb = (n * (-1));
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(int n)
{
	unsigned int	l;
	char			*new;
	unsigned int	nb;

	nb = n;
	l = ft_len(n);
	if (!(new = (char*)malloc(sizeof(char) * l + 1)))
		return (NULL);
	new[l--] = '\0';
	if (nb == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		new[0] = '-';
		nb = n * -1;
	}
	while (nb > 0)
	{
		new[l] = (nb % 10) + 48;
		nb = nb / 10;
		l--;
	}
	return (new);
}
