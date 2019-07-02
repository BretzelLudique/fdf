/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 02:51:07 by czhang            #+#    #+#             */
/*   Updated: 2019/07/02 07:27:07 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mlx	create_mlx(void)
{
	t_mlx	r;

	r.mlx_ptr = mlx_init();
	r.win_ptr = mlx_new_window(r.mlx_ptr, WIDTH, HEIGHT, "TEST");
	r.img.img_ptr = mlx_new_image(r.mlx_ptr, WIDTH, HEIGHT);
	r.img.img_str = mlx_get_data_addr(r.img.img_ptr,
		&r.img.bpp, &r.img.size_line, &r.img.endian);
	return (r);
}

static int		reterr(char const *s, t_tab *tab, t_tab *tab2)
{
	ptit_free(tab);
	ptit_free(tab2);
	if (s)
		ft_putendl_fd(s, 2);
	return (0);
}

static t_coord	*update_range(t_tab *iso)
{
	static t_coord	range[2];
	int				x;
	int				y;
	t_coord			**data;

	data = (t_coord **)iso->data;
	range[0].x = 0;
	range[0].y = 0;
	range[1].x = 0;
	range[1].y = 0;
	x = -1;
	while (++x < iso->x_size)
	{
		y = -1;
		while (++y < iso->y_size)
		{
			range[0].x = range[0].x < data[y][x].x ? range[0].x : data[y][x].x;
			range[0].y = range[0].y < data[y][x].y ? range[0].y : data[y][x].y;
			range[1].x = range[1].x > data[y][x].x ? range[1].x : data[y][x].x;
			range[1].y = range[1].y > data[y][x].y ? range[1].y : data[y][x].y;
		}
	}
	return (range);
}

static int		resize_coord(t_tab *iso, t_coord range[2])
{
	t_coord **data;
	double	coeff;

	data = (t_coord **)iso->data;
	substract_t_coord(iso, range[0]);
	update_range(iso);
	if (range[1].x <= WIDTH && range[1].y <= HEIGHT)
		return (1);
	coeff = (double)range[1].x / (double)WIDTH;
	if (coeff < (double)range[1].y / (double)HEIGHT)
		coeff = (double)range[1].y / (double)HEIGHT;
	coeff = coeff - (int)coeff == 1 ? (int)coeff : (int)coeff + 1;
	divide_t_coord(iso, coeff);
	update_range(iso);
	return (0);
}

int				main(int ac, char **av)
{
	t_mlx	r;
	t_tab	*tab;
	t_tab	*iso;

	if (ac != 2)
		return (reterr("bad arguments", 0, 0));
	if (!(tab = new_tab(0, 0, 0)) || !(read_file(tab, av[1])))
		return (reterr("read_file", tab, 0));
	if (!(iso = new_tab(0, tab->x_size, tab->y_size)) || !tab_iso(iso, tab))
		return (reterr("tab_iso", tab, iso));
	r = create_mlx();
	resize_coord(iso, update_range(iso));
	draw(iso, r);
	mlx_put_image_to_window(r.mlx_ptr, r.win_ptr, r.img.img_ptr, 0, 0);
	mlx_key_hook(r.win_ptr, interrupt, &r);
	mlx_loop(r.mlx_ptr);
	ptit_free(tab);
	ptit_free(iso);
	return (0);
}
