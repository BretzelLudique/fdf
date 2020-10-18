/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 02:24:32 by czhang            #+#    #+#             */
/*   Updated: 2019/09/02 14:52:58 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	get_coord(int x, int y, int z, double angle[2])
{
	t_coord coord;

	coord.x = 20 * (cos(angle[0]) * (double)x - sin(angle[0]) * (double)y);
	coord.y = 20 * (-sin(angle[0]) * sin(angle[1]) * (double)x - cos(angle[0])
			* sin(angle[1]) * (double)y + cos(angle[1]) * (double)z);
	return (coord);
}

static int		add_line_coord(t_tab *iso, int y, t_tab *tint, double angle[2])
{
	t_coord	*line_iso;
	int		*line_int;
	int		x;

	if (!(line_iso = (t_coord *)ft_memalloc(sizeof(t_coord) * tint->x_size)))
		return (0);
	line_int = (int *)tint->data[y];
	x = -1;
	while (++x < tint->x_size)
		line_iso[x] = get_coord(x, -y, -line_int[x], angle);
	iso->data[y] = line_iso;
	return (1);
}

int				tab_coord(t_tab *tiso, t_tab *tint, double angle[2])
{
	int		y;

	if (!tint || !tint->data)
		return (0);
	if (!(tiso->data = (void **)ft_memalloc(sizeof(t_coord *) * tint->y_size)))
		return (0);
	y = 0;
	while (y < tint->y_size)
		if (!(add_line_coord(tiso, y++, tint, angle)))
		{
			tiso->y_size = y;
			return (0);
		}
	return (1);
}
