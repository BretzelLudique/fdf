#include "fdf.h"

static int	draw_pixel(int x, int y, int color)
{
	t_mlx	a;


	if (!color)
		color = 200;
	a = get_a();
	return (mlx_pixel_put(a.mlx_ptr, a.win_ptr, x, y, color));
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

static int	draw_once(t_coord a, t_coord b)
{
	int		x;
	int		y;
	double	m;
	double	p;

	m = (double) (b.y - a.y) / (b.x - a.x);
	p = b.y - m *a.x;
	x = a.x;
	draw_pixel(a.x, a.y, 0);
	while (++x <= b.x)
	{
		y = (int) (m * x + p);
		draw_pixel(x, y, 0);
	}
	return (1);
}

static int	draw_y(t_coord a, t_coord b)
{
	int	y;

	y = a.y;
	draw_pixel(a.x, y, 0);
	while (++y <= b.y)
		draw_pixel(a.x, y, 0);
	return (1);
}

static int	draw_segment(t_coord a, t_coord b)
{
	draw_once(a, b);
	draw_once(b, a);
	return (1);
}

int			draw(t_tab *tab)
{
	int		x;
	int		y;
	t_coord	**coord;

	coord = (t_coord **)tab->data;
	y = 0;
	while (++y < tab->x_size)
	{
		draw_segment(coord[0][y], coord[0][y - 1]);
	}
	x = 0;
	while (++x < tab->y_size)
		draw_segment(coord[x][0], coord[x - 1][0]);
	while (--x)
	{
		y = tab->x_size;
		while (--y)
		{
			draw_segment(coord[x][y - 1], coord[x][y]);
			draw_segment(coord[x - 1][y], coord[x][y]);
		}
	}
	return (1);
}
