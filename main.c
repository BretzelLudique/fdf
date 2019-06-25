/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 02:51:07 by czhang            #+#    #+#             */
/*   Updated: 2019/06/25 15:59:53 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int         draw_segment(t_coord a, t_coord b, t_mlx r);

t_img	create_img(t_mlx r)
{
	t_img	img;

	img.img_ptr = mlx_new_image(r.mlx_ptr, 800, 600);
	img.img_str = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line, &img.endian);
	return (img);
}

t_mlx	create_mlx()
{
	t_mlx	r;

	r.mlx_ptr = mlx_init();
	r.win_ptr = mlx_new_window(r.mlx_ptr, 800, 600, "TEST");
	r.img = create_img(r);
	return (r);
}

void	print_coord(t_tab *tab)
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

void	truc(char *nom_var, int var_aff)
{
	ft_putstr(nom_var);
	ft_putstr(" = ");
	ft_putnbr(var_aff);
	ft_putendl("");
}

int		test(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl("bad arguments");
		return (0);
	}
	(void)av;
	return (1);
}

void	test_draw(t_mlx r)
{
	t_coord	a;
	t_coord	b;

	a.x = 200;
	a.y = 400;
	b.x = 500;
	b.y = 500;
	draw_segment(a, b, r);
}

int		main(int ac, char **av)
{
	t_mlx	r;
	t_tab	*tab;
	t_tab	*iso;

	if (!test(ac, av))
		return (-1);
	if (!(tab = read_file(av[1])) || (!(iso = tab_iso(tab))))
		return (-1);
	r = create_mlx();
//	draw(iso, r);
//	truc("x_size", iso->x_size);
//	truc("y_size", iso->y_size);
//	print_coord(iso);
	test_draw(r);
	mlx_put_image_to_window(r.mlx_ptr, r.win_ptr, r.img.img_ptr, 0, 0);
	mlx_loop(r.mlx_ptr);
	return (0);
}
