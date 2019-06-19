/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 02:46:42 by czhang            #+#    #+#             */
/*   Updated: 2019/06/19 04:49:08 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include "mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef struct	s_img
{
	void	*img_ptr;
	char	*img_str;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef	struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_mlx;

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_tab
{
	void	**data;
	int		x_size; // taille exacte
	int		y_size;
}				t_tab;

int		main(int ac, char **av);
t_tab	*read_file(char *filename);
void	ptit_free(t_tab *tab);
t_tab	*new_tab(void **data, int x_size, int y_size);
t_tab	*tab_iso(t_tab *tab_int);
int		draw(t_tab *tab, t_mlx r);
t_mlx	get_r();

#endif
