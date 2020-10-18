/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 04:19:15 by czhang            #+#    #+#             */
/*   Updated: 2019/09/19 03:48:35 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*extend_str(char *str, char *end, int *strlen)
{
	char	*newstr;
	int		totalsize;
	int		i;
	int		endlen;

	endlen = ft_strlen(end);
	totalsize = *strlen + endlen + 2;
	if (!(newstr = (char*)ft_strnew(sizeof(char) * (*strlen + endlen + 2))))
		return (0);
	if (*strlen)
	{
		ft_strncpy(newstr, str, *strlen);
		newstr[(*strlen)++] = '\n';
	}
	i = -1;
	while (++i < endlen)
		newstr[(*strlen)++] = end[i];
	newstr[(*strlen)] = '\0';
	ft_memdel((void**)&str);
	return (newstr);
}

static char	*get_str(int fd, t_tab *tab)
{
	int		n;
	int		strlen;
	char	*str;
	char	*line;

	strlen = 0;
	n = 0;
	if (!(str = ft_strnew(0)))
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		n++;
		if (!(str = extend_str(str, line, &strlen)))
		{
			ft_memdel((void**)&line);
			return (0);
		}
		ft_memdel((void**)&line);
	}
	if (!(tab->y_size = n) || !str || ft_strlen(str) == 0)
	{
		ft_putendl_fd("No data found.", 2);
		return (0);
	}
	return (str);
}

static int	add_line_int(t_tab *tab, int y, char *str, int *strpos)
{
	int	*lineint;
	int	x;

	x = 0;
	while (str[*strpos + x] && str[*strpos + x] != '\n')
		x++;
	if (tab->x_size != ft_cntwrdn(str + *strpos, ' ', '\n', x))
		return (reterr_xsize());
	if (!(lineint = (int *)ft_memalloc(sizeof(int) * (tab->x_size))))
		return (0);
	x = -1;
	while (++x < tab->x_size)
	{
		while (str[*strpos] == ' ')
			(*strpos)++;
		lineint[x] = ft_atoi(str + *strpos);
		while (str[*strpos] && str[*strpos] != ' ' && str[*strpos] != '\n')
			(*strpos)++;
	}
	while (str[*strpos] == ' ' || str[*strpos] == '\n')
		(*strpos)++;
	tab->data[y] = (void*)lineint;
	return (1);
}

static int	get_tabint(t_tab *tab, char *str)
{
	int	i;
	int	y;
	int	tabsize;

	tabsize = ft_cntwrd2(str, ' ', '\n');
	tab->x_size = tabsize / tab->y_size;
	if (tab->x_size * tab->y_size != tabsize)
	{
		tab->y_size = 0;
		ft_putendl_fd("Found wrong line length. Exiting.", 2);
		return (0);
	}
	if (!(tab->data = (void**)ft_memalloc(sizeof(int*) * tab->y_size)))
		return (0);
	i = 0;
	y = -1;
	while (++y < tab->y_size && str[i])
	{
		if (!(add_line_int(tab, y, str, &i)))
		{
			tab->y_size = y;
			return (0);
		}
	}
	return (1);
}

int			read_file(t_tab *tab, char *filename)
{
	char	*str;
	int		fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_putstr_fd("No file ", 2);
		ft_putendl_fd(filename, 2);
		close(fd);
		return (0);
	}
	if (!(str = get_str(fd, tab)) || !get_tabint(tab, str))
	{
		ft_memdel((void**)&str);
		close(fd);
		return (0);
	}
	ft_memdel((void**)&str);
	close(fd);
	return (1);
}
