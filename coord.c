/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 05:16:15 by czhang            #+#    #+#             */
/*   Updated: 2019/07/02 04:13:55 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	get_iso(int x, int y, int z)
{
	t_coord	coord;

	coord.x = (71 * (x - y)) / 5;
	coord.y = ((-41 * (x + y) + 82 * z) / 5);
	return (coord);
}

static int		add_line_iso(t_tab *iso, int y, t_tab *tint)
{
	t_coord	*line_iso;
	int		*line_int;
	int		x;

	if (!(line_iso = (t_coord *)malloc(sizeof(t_coord) * tint->x_size)))
		return (0);
	line_int = (int *)tint->data[y];
	x = -1;
	while (++x < tint->x_size)
		line_iso[x] = get_iso(x, -y, -line_int[x]);
	iso->data[y] = line_iso;
	return (1);
}

int				tab_iso(t_tab *tab_iso, t_tab *tint)
{
	int		y;

	if (!tint || !tint->data)
		return (0);
	if (!(tab_iso->data = (void **)malloc(sizeof(t_coord *) * tint->y_size)))
		return (0);
	y = 0;
	while (y < tint->y_size)
		if (!(add_line_iso(tab_iso, y++, tint)))
		{
			tab_iso->y_size = y;
			return (0);
		}
	return (1);
}
