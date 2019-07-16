/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 04:19:15 by czhang            #+#    #+#             */
/*   Updated: 2019/07/16 09:29:04 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**free_tabchar(char **tabchar)
{
	int	n;

	if (!tabchar)
		return (0);
	n = 0;
	while (tabchar[n])
		n++;
	while (n--)
		ft_memdel((void**)&tabchar[n]);
	ft_memdel((void**)&tabchar);
	return (0);
}

static int	add_line_int(t_tab *tab, int i, char **tabline)
{
	int	*lineint;
	int	x_size;

	if (!tabline)
		return (0);
	x_size = 0;
	while (tabline[x_size])
		x_size++;
	if (!tab->x_size)
		tab->x_size = x_size;
	if (tab->x_size != x_size)
	{
		ft_putendl_fd("Found wrong line length. Exiting.", 2);
		return (0);
	}
	if (!(lineint = (int *)malloc(sizeof(int) * (x_size))))
		return (0);
	while (--x_size >= 0)
		lineint[x_size] = ft_atoi(tabline[x_size]);
	tab->data[i] = lineint;
	free_tabchar(tabline);
	return (1);
}

static char	**realloc_tabchar(char **tabchar, int new_size)
{
	char	**newtabchar;
	int		i;

	if (!(newtabchar = (char**)ft_memalloc(sizeof(char*) * new_size + 1)))
	{
		i = -1;
		free_tabchar(tabchar);
		return (0);
	}
	i = -1;
	while (++i < new_size - 1)
		newtabchar[i] = tabchar[i];
	newtabchar[new_size - 1] = 0;
	newtabchar[new_size] = 0;
	i = -1;
	ft_memdel((void**)&tabchar);
	return (newtabchar);
}

static char	**get_data(int fd, t_tab *tab)
{
	int		n;
	char	**tabchar;
	char	*line;

	n = 0;
	if (!(tabchar = (char**)ft_memalloc(sizeof(char*))))
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		n++;
		if (!(tabchar = realloc_tabchar(tabchar, n)))
			return (0);
		tabchar[n - 1] = ft_strdup(line);
		ft_memdel((void**)&line);
	}
	if (!tabchar[0] || ft_strlen(tabchar[0]) == 0)
	{
		ft_putendl_fd("No data found.", 2);
		return (free_tabchar(tabchar));
	}
	tab->y_size = n;
	if (!(tab->data = (void **)malloc(sizeof(int *) * n)))
		return (free_tabchar(tabchar));
	return (tabchar);
}

int			read_file(t_tab *tab, char *filename)
{
	char	**tabchar;
	int		y;
	int		fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_putstr_fd("No file ", 2);
		ft_putendl_fd(filename, 2);
		return (0);
	}
	if (!(tabchar = get_data(fd, tab)))
		return (0);
	y = -1;
	while (tabchar && tabchar[++y])
		if (!(add_line_int(tab, y, ft_strsplit(tabchar[y], ' '))))
		{
			tab->y_size = y;
			free_tabchar(tabchar);
			close(fd);
			return (0);
		}
	free_tabchar(tabchar);
	close(fd);
	return (1);
}
