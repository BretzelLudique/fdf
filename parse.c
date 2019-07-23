/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 04:19:15 by czhang            #+#    #+#             */
/*   Updated: 2019/07/23 06:54:44 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_tabchar(char **tabchar)
{
	int	n;

	if (!tabchar)
		return ;
	n = 0;
	while (tabchar[n])
		n++;
	while (n--)
		ft_memdel((void**)&tabchar[n]);
	ft_memdel((void**)&tabchar);
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
		free_tabchar(tabchar);
		ft_putendl_fd("No data found.", 2);
		return (0);
	}
	tab->y_size = n;
	if (!(tab->data = (void **)malloc(sizeof(int *) * n)))
	{
		free_tabchar(tabchar);
		return (0);
	}
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
static char	*extend_str(char *str, char *end, int *strlen)
{
	char	*newstr;
	int		totalsize;
	int		i;
	int		endlen;

	endlen = ft_strlen(end);
	totalsize = *strlen + endlen + 2;
	if (!(newstr = (char*)ft_strnew(sizeof(char) * (*strlen + endlen + 2))))
	{
		ft_memdel((void**)&str);
		ft_memdel((void**)&end);
		return (0);
	}
	ft_strcpy(newstr, str);
	newstr[(*strlen)++] = '\n';
	i = -1;
	while (++i < endlen)
		newstr[(*strlen)++] = end[i];
	newstr[(*strlen)++] = 0;
	ft_memdel((void**)&str);
	ft_memdel((void**)&end);
	return (newstr);
}

static char	*get_data(int fd, t_tab *tab)
{
	int		n;
	int		strlen;
	char	*str;
	char	*line;

	strlen = 0;
	n = 0;
	while (get_next_line(fd, &line) > 0)
	{
		n++;
		if (!(str = extend_str(str, line, &strlen)))
			return (0);
	}
	if (!str || ft_strlen(str) == 0)
	{
		ft_putendl_fd("No data found.", 2);
		ft_memdel((void**)&str);
		return (0);
	}
	tab->y_size = n;
	return (str);
}

int			get_tabint(t_tab *tab, char *str)
{
	int	i;
	int	j;
	int	tabsize;
	int	*data;

	tabsize = ft_cntwrd(str, ' ');
	if (!(data = (int*)ft_memalloc(sizeof(int) * tabsize)))
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		data[j++] = ft_atoi(str + i);
		while (str[i] && str[i] != ' ')
			i++;
	}
	tab->data = data;
	return (1);
}

int			read_file(t_tab *tab, char *filename)
{
	char	*str;
	int		y;
	int		fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_putstr_fd("No file ", 2);
		ft_putendl_fd(filename, 2);
		return (0);
	}
	if (!(str = get_data(fd, tab)))
		return (0);
	if (!get_tabint(tab, str))
	{
		ft_memdel((void**)&str);
		close(fd);
		return (0);
	}
	ft_memdel((void**)&str);
	close(fd);
	return (1);
}
