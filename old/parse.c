#include "fdf.h"

static int	add_line_int(t_tab *tab, int i, char **tabchar)
{
	int	*lineint;
	int	x_size;

	if (!tabchar)
	{
		perror("malloc tabchar");
		return (0);
	}
	x_size = 0;
	while (tabchar[x_size])
		x_size++;
	if (!tab->x_size)
		tab->x_size = x_size;
	if (tab->x_size != x_size)
	{
		perror("fichier non valide : x_size non valide");
		return (0);
	}
	if(!(lineint = (int *)malloc(sizeof(int) * (x_size))))
	{
		perror("malloc lineint");
		return (0);
	}
	while (--x_size >= 0)
		lineint[x_size] = ft_atoi(tabchar[x_size]);
	tab->data[i] = lineint;
	return (1);
}

static int	get_n_lines(char *filename)
{
	int		n;
	int		fd;
	char	*line;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		perror("open fd");
		return (0);
	}
	n = 0;
	while (get_next_line(fd, &line))
		n++;
	close(fd);
	free(line);
	return (n);
}

t_tab			*reterr(char const *s, t_tab *tab)
{
	ptit_free(tab);
	perror(s);
	return (0);
}

t_tab			*read_file(char *filename)
{
	char	*line;
	t_tab	*tab;
	int		y;
	int		fd;

	if (!(tab = new_tab(0, 0, 0)))
		return (reterr("malloc tab", tab));
	if (!(tab->y_size = get_n_lines(filename)))
		return (reterr("tab->y_size", tab));
	if (!(tab->data = (void **)malloc(sizeof(int *) * (tab->y_size))))
		return (reterr("malloc tab->data", tab));
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (reterr("open fd", tab));
	y = 0;
	while (get_next_line(fd, &line))
		if (!(add_line_int(tab, y++, ft_strsplit(line, ' '))))
		{
			tab->y_size = y;
			return (reterr("malloc tab->data[i]", tab));
		}
	free(line);
	close(fd);
	return (tab);
}
