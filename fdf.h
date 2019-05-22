#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include "minilibx/mlx.h"
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
	int		x_size;
	int		y_size;
}				t_tab;

int		main(int ac, char **av);
t_tab	*read_file(char *filename);
void	ptit_free(t_tab *tab);
t_tab	*new_tab(void **data, int x_size, int y_size);
t_tab	*tab_iso(t_tab *tab_int);
int		draw(t_tab *tab);
t_mlx	get_a();

#endif
