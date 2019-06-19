/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 22:59:29 by czhang            #+#    #+#             */
/*   Updated: 2019/06/19 08:11:29 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	draw_pixel(int x, int y, t_mlx r)
{
	t_img img;
	char	*c;
	int	*i;

	img = r.img;
	c = img.img_str + ( 4 * x + img.size_line  * y) ;
	i = (int *)c;
	*i = 0xffffff;
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

int			draw_once(t_coord a, t_coord b, t_mlx r)
{
	int		dx;
	int		dy;
	int		e;
	t_coord	save_a;

	save_a.x = a.x;
	save_a.y = a.y;
	e = b.x - a.x;
	dx = 2 * e;
	dy = (b.y - a.y) * 2;
	while (a.x <= b.x)
	{
		draw_pixel(a.x, a.y, r);
		a.x++;
		if ((e = e - dy) <= 0)
		{
			a.y++;
			e += dx;
		}
	}
	draw_pixel(b.x, b.y, r);
	a.x = save_a.x;
	a.y = save_a.y;
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

int			draw_segment(t_coord a, t_coord b, t_mlx r)
{
	ft_putendl("on trace");
	ft_putstr("a.x = ");
	ft_putnbr(a.x);
	ft_putstr("  a.y = ");
	ft_putnbr(a.y);
	ft_putendl("");
	ft_putstr("b.x = ");
	ft_putnbr(b.x);
	ft_putstr("  b.y = ");
	ft_putnbr(b.y);
	ft_putendl("\n");
	draw_once(a, b, r);
	draw_once(b, a, r);
	return (1);
}

int			draw(t_tab *tab, t_mlx r)
{
	int		x;
	int		y;
	t_coord	**coord;
//	t_coord	a;
//	t_coord b;

	coord = (t_coord **)tab->data;
	y = -1;
	while (++y < tab->y_size)
	{
		x = -1;
		while (++x < tab->x_size)
		{
			if (y)
				draw_segment(coord[y - 1][x], coord[y][x], r);
			if (x)
				draw_segment(coord[y][x - 1], coord[y][x], r);
		}
	}
//	a.x = 0;
//	a.y = 600;
//	b.x = 799;
//	b.y = 0;
//	draw_segment(a, b, r);
	return (1);
}
