#include "fdf.h"

t_mlx	get_a()
{
	static t_mlx	a;
	t_image			*img;

	if (!a.mlx_ptr && !a.win_ptr)
	{
		a.mlx_ptr = mlx_init();
		a.win_ptr = mlx_new_window(a.mlx_ptr, 800, 600, "TEST");
		a.img.img_ptr = mlx_new_image(a.mlx_ptr, 800, 600);
		a.img.img_str = mlx_get_data_adrr(a.img.img_ptr, 
	}
	return (a);
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
	t_mlx	a;
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
	print_coord(test);
	a = get_a();
	//draw(iso);
	draw(test);
	mlx_loop(a.mlx_ptr);
	return (0);
}
