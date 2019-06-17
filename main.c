/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 02:51:07 by czhang            #+#    #+#             */
/*   Updated: 2019/06/17 04:12:19 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int		main(int ac, char **av)
{
	t_mlx	r;

	if (!test(ac, av))
		return (-1);
	r = create_mlx();

}
