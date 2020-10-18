/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repeat_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:34:35 by ccarole           #+#    #+#             */
/*   Updated: 2019/04/29 15:14:45 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_repeat(char c)
{
	int			rept;

	rept = 1;
	if (c >= 'a' && c <= 'z')
		rept = c - 'a' + 1;
	if (c >= 'A' && c <= 'Z')
		rept = c - 'A' + 1;
	return (rept);
}

int				ft_repeat_alpha(int ac, char **av)
{
	int			rept;
	int			i;

	i = 0;
	if (ac != 2)
	{
		ft_putchar('\n');
	}
	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			rept = (ft_nb_repeat(av[1][i]));
			while (rept > 0)
			{
				ft_putchar(av[1][i]);
				rept--;
			}
			i++;
		}
		ft_putchar('\n');
	}
	return (0);
}
