/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_necessaire.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 22:28:03 by czhang            #+#    #+#             */
/*   Updated: 2019/07/02 03:49:10 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_coord(t_tab *tab)
{
	t_coord **coord;
	int		x;
	int		y;

	coord = (t_coord **)tab->data;
	y = -1;
	while (++y < tab->y_size)
	{
		x = -1;
		while (++x < tab->x_size)
		{
			ft_putstr("(");
			ft_putnbr(coord[y][x].x);
			ft_putstr("; ");
			ft_putnbr(coord[y][x].y);
			ft_putstr(")  ");
		}
		ft_putchar('\n');
	}
}
