/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 22:11:52 by czhang            #+#    #+#             */
/*   Updated: 2019/06/17 00:54:08 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	get_r()
{
	t_mlx			r;
	t_img			img;

	if (!r.mlx_ptr && !r.win_ptr)
	{
		img = r.img;
		r.mlx_ptr = mlx_init();
		r.win_ptr = mlx_new_window(r.mlx_ptr, 800, 600, "TEST");
		img.img_ptr = mlx_new_image(r.mlx_ptr, 800, 600);
		img.img_str = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line, &img.endian);
	}
	return (r);
}

/*
static int	print_tabint(t_tab *tab)
{
	int	x;
	int	y;

	x = -1;
	while (x < tab->y_size)	
}
*/
void	nbr(char *str, int nbr)
{
	ft_putstr(str);
	ft_putstr(" = ");
	ft_putnbr(nbr);
	ft_putendl("");
}

void	crd(char *str, t_coord coord)
{
	ft_putstr(str);
	ft_putstr(" = (");
	ft_putnbr(coord.x);
	ft_putstr("; ");
	ft_putnbr(coord.y);
	ft_putendl(")");
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

t_tab	*tab_test()
{
	t_tab	*tab;
	t_coord	**coord;
	int		x;
	int		y;


	coord = (t_coord **)malloc(sizeof(t_coord *) * 6);
	y = -1;
	while (++y < 6)
	{
		coord[y] = (t_coord *)malloc(sizeof(t_coord) * 6);
		x = -1;
		while (++x < 6)
		{
			coord[y][x].x = x * 20 + 200;
			coord[y][x].y = y * 20 + 200;
		}
	}
	tab = new_tab((void **)coord, 6, 6);
	return (tab);
}

int		main(int ac, char **av)
{
	t_mlx	r;
	t_tab	*tab;
	t_tab	*iso;
	t_tab	*test;
	int		y;

	if (ac != 2)
	{
		ft_putendl("bad arguments");
		return (-1);
	}
	if (!(tab = read_file(av[1])))
	{
		perror("init tab dans main");
		return (-1);
	}
	if (!(iso = tab_iso(tab)))
	{
		perror("iso dans main");
		return (-1);
	}
	y = -1;
	/*
	nbr("iso->x_size", iso->y_size);
	while (++ y < iso->y_size)
		crd("iso->data[y][0]", ((t_coord **)iso->data)[y][0]);
	print_coord(iso);
	*/
	test = tab_test();
	print_coord(tab);
	r = get_r();
	//draw(iso);
	draw(tab, r);
	mlx_loop(r.mlx_ptr);
	return (0);
}
