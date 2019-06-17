/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 22:59:29 by czhang            #+#    #+#             */
/*   Updated: 2019/06/17 04:18:10 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	draw_pixel(int x, int y, t_mlx r)
{
	t_img img;

	img = r.img;
	img.img_str[4 * (x +img.size_line * y)] = -1;
	return (1);
}

/*
static int	draw_once(t_coord a, t_coord b)
{
	int	dp;
	int	x;
	int	y;

	x = a.x;
	y = a.y;
	a.x = b.x - a.x;
	a.y = b.y - a.y;
	dp = 2 * a.y - a.x;
	draw_pixel(x, y, 0);
	while (x <= b.x)
	{
		if (dp <= 0)
			dp += 2 * a.y;
		else
		{
			dp += 2 * (a.y - a.x);
			y++;
		}
		x++;
		draw_pixel(x, y, 0);
	}
	return (1);
}
*/

static int	draw_once(t_coord a, t_coord b, t_mlx r)
{
	int		x;
	int		y;
	double	m;
	double	p;

	m = (double) (b.y - a.y) / (b.x - a.x);
	p = b.y - m *a.x;
	x = a.x;
	draw_pixel(a.x, a.y, r);
	while (++x <= b.x)
	{
		y = (int) (m * x + p);
		draw_pixel(x, y, r);
	}
	return (1);
}

/*
static int	draw_y(t_coord a, t_coord b, t_mlx r)
{
	int	y;

	y = a.y;
	draw_pixel(a.x, y, r);
	while (++y <= b.y)
		draw_pixel(a.x, y, r);
	return (1);
}
*/

static int	draw_segment(t_coord a, t_coord b, t_mlx r)
{
	draw_once(a, b, r);
	draw_once(b, a, r);
	return (1);
}

int			draw(t_tab *tab, t_mlx r)
{
	int		x;
	int		y;
	t_coord	**coord;

	coord = (t_coord **)tab->data;
	y = 0;
	while (++y < tab->x_size)
		draw_segment(coord[0][y], coord[0][y - 1], r);
	x = 0;
	while (++x < tab->y_size)
		draw_segment(coord[x][0], coord[x - 1][0], r);
	while (--x)
	{
		y = tab->x_size;
		while (--y)
		{
			draw_segment(coord[x][y - 1], coord[x][y], r);
			draw_segment(coord[x - 1][y], coord[x][y], r);
		}
	}
	return (1);
}
