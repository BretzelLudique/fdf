#include "fdf.h"
#include <math.h>

static t_coord	get_iso(int x, int y, int z)
{
	t_coord	coord;

	coord.x = (71 * (x - y)) / 5 + 220;
	coord.y = ((-41 * (x + y) + 82 * z) / 5) + 420;
	return (coord);
}

/*
static t_coord	get_iso(int x, int y, int z)
{
	t_coord	coord;
	float	xiso;
	float	yiso;
	float	racine2sur2;
	float	racine2surracine3;
	float	surracine6;

	racine2sur2 = cos(M_PI / 4);
	racine2surracine3 = cos(M_PI / 4) / cos(M_PI / 6);
	surracine6 = cos(M_PI / 4) * tan (M_PI / 3) / 3;
	xiso = racine2sur2 * ((float)x - (float)y);
	yiso = -surracine6 * ((float)x + (float)y) + racine2surracine3 * (float)z;

	xiso *= 20;
	yiso *= 20;
	xiso += 300;
	yiso += 300;
	coord.x = (int)xiso;
	coord.y = (int)yiso;
	return (coord);
}
*/

static int		add_line_iso(t_tab *iso, int y, t_tab *tint)
{
	t_coord	*line_iso;
	int		*line_int;
	int		x;

	if (!(line_iso = (t_coord *)malloc(sizeof(t_coord) * tint->x_size)))
	{
		perror("malloc tab_iso->data[x]");
		return (0);
	}
	line_int = (int *)tint->data[y];
	x = -1;
	while (++x < tint->x_size)
		line_iso[x] = get_iso(x, -y, line_int[x]);
	iso->data[y] = line_iso;
	return (1);
}

t_tab		*tab_iso(t_tab *tint)
{
	t_tab	*iso;
	int		y;

	if (!tint || !tint->data)
	{
		perror("tab int nul");
		return (0);
	}
	if (!(iso = new_tab(0, tint->x_size, tint->y_size)))
	{
		perror("malloc tab_iso");
		return (0);
	}
	if (!(iso->data = (void **)malloc(sizeof(t_coord *) * tint->y_size)))
	{
		perror("malloc tab_iso->data");
		ptit_free(iso);
		return (0);
	}
	y = 0;
	while (y < iso->y_size)
	{
		if (!(add_line_iso(iso, y++, tint)))
		{
			iso->y_size = y;
			perror("malloc line_iso");
			ptit_free(iso);
			return (0);
		}
	}
	return (iso);
}

/*
int		draw_iso(int **tab)
{
	int	x;
	int	y;

	x = -1;
	while (tab[++x + 1])
	{
		y_map = -1;
		while (tab[x][++y + 1] != -42424242)
		{
			draw_segment(iso(x, y, tab[x][y]), iso(x + 1, y + 1, tab[x + 1][y + 1]));
			draw_segment(iso(x, y, tab[x][y]), 
		}
	}
}
*/
