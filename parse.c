/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 04:19:15 by czhang            #+#    #+#             */
/*   Updated: 2019/07/02 03:07:12 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	add_line_int(t_tab *tab, int i, char **tabchar)
{
	int	*lineint;
	int	x_size;

	if (!tabchar)
		return (0);
	x_size = 0;
	while (tabchar[x_size])
		x_size++;
	if (!tab->x_size)
		tab->x_size = x_size;
	if (tab->x_size != x_size)
	{
		ft_putstr_fd("every line needs to have the same size in ", 2);
		return (0);
	}
	if (!(lineint = (int *)malloc(sizeof(int) * (x_size))))
		return (0);
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
		ft_putstr_fd("error open in ", 2);
		return (0);
	}
	n = 0;
	while (get_next_line(fd, &line))
		n++;
	close(fd);
	free(line);
	return (n);
}

int			read_file(t_tab *tab, char *filename)
{
	char	*line;
	int		y;
	int		fd;

	if (!(tab->y_size = get_n_lines(filename)))
		return (0);
	if (!(tab->data = (void **)malloc(sizeof(int *) * (tab->y_size))))
		return (0);
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	y = 0;
	while (get_next_line(fd, &line))
		if (!(add_line_int(tab, y++, ft_strsplit(line, ' '))))
		{
			tab->y_size = y - 1;
			if (line)
				free(line);
			close(fd);
			return (0);
		}
	free(line);
	close(fd);
	return (1);
}
