/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 22:59:29 by czhang            #+#    #+#             */
/*   Updated: 2019/07/02 01:51:50 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	draw_pixel(int x, int y, t_mlx r)
{
	int		*i;

	i = (int *)(r.img.img_str + 4 * x + r.img.size_line * y);
	*i = 0xffffff;
	return (1);
}

static int	draw_x(t_coord a, t_coord b, t_mlx r)
{
	int	dx;
	int	dy;
	int	e;

	e = b.x - a.x;
	dx = 2 * e;
	dy = 2 * (b.y - a.y);
	if (dy == 0)
	{
		while (a.x <= b.x)
			draw_pixel(a.x++, a.y, r);
		return (1);
	}
	while (a.x <= b.x)
	{
		draw_pixel(a.x++, a.y, r);
		e = dy > 0 ? e - dy : e + dy;
		if (e < 0)
		{
			a.y = dy > 0 ? a.y + 1 : a.y - 1;
			e += dx;
		}
	}
	return (1);
}

static int	draw_y(t_coord a, t_coord b, t_mlx r)
{
	int	dx;
	int	dy;
	int	e;

	e = b.y - a.y;
	dx = 2 * (b.x - a.x);
	dy = 2 * e;
	if (dx == 0)
	{
		while (a.y <= b.y)
			draw_pixel(a.x, a.y++, r);
		return (1);
	}
	while (a.y <= b.y)
	{
		draw_pixel(a.x, a.y++, r);
		e = dx > 0 ? e - dx : e + dx;
		if (e < 0)
		{
			a.x = dx > 0 ? a.x + 1 : a.x - 1;
			e += dy;
		}
	}
	return (1);
}

static int	draw_segment(t_coord a, t_coord b, t_mlx r)
{
	int		dx;
	int		dy;

	if (!(dx = b.x - a.x))
		return (((dy = b.y - a.y) > 0) ? draw_y(a, b, r) : draw_y(b, a, r));
	if (!(dy = b.y - a.y))
		return (dx > 0 ? draw_x(a, b, r) : draw_x(b, a, r));
	if (dx > 0)
	{
		if (dy > 0)
			return (dx >= dy ? draw_x(a, b, r) : draw_y(a, b, r));
		else
			return (dx >= -dy ? draw_x(a, b, r) : draw_y(b, a, r));
	}
	if (dy > 0)
		return ((-dx >= dy) ? draw_x(b, a, r) : draw_y(a, b, r));
	else
		return ((dx <= dy) ? draw_x(b, a, r) : draw_y(a, b, r));
}

int			draw(t_tab *tab, t_mlx r)
{
	int		x;
	int		y;
	t_coord	**coord;

	coord = (t_coord **)tab->data;
	y = -1;
	while (++y < tab->y_size)
	{
		x = -1;
		while (++x < tab->x_size)
		{
			if (y && x != 0)
				draw_segment(coord[y - 1][x], coord[y][x], r);
			if (x && y != tab->y_size - 1)
				draw_segment(coord[y][x - 1], coord[y][x], r);
		}
	}
	return (1);
}
