/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:16:53 by czhang            #+#    #+#             */
/*   Updated: 2019/07/05 02:36:36 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		fill_line(char **line, char **abuffer, int len_fin)
{
	char	*dup_line;
	int		len;
	int		i;

	len = 0;
	if (*line == NULL || **line == '\0')
	{
		if (!(*line = (char*)ft_memalloc(sizeof(char) * (len_fin + 1))))
			return (-1);
	}
	else
	{
		len = ft_strlen(*line);
		dup_line = ft_strdup(*line);
		ft_memdel((void**)line);
		if (!(*line = (char*)ft_memalloc(sizeof(char) * (len + len_fin + 1))))
			return (-1);
		ft_strcpy(*line, dup_line);
		ft_memdel((void**)&dup_line);
	}
	i = -1;
	while (++i < len_fin)
		(*line)[len + i] = (*abuffer)[i];
	return (0);
}

static int		ft_truc(char **line, char **abuffer)
{
	char	*dup_line;
	int		len_fin;

	len_fin = 0;
	while ((*abuffer)[len_fin] != '\0' && (*abuffer)[len_fin] != '\n')
		len_fin++;
	if (fill_line(line, abuffer, len_fin) == -1)
		return (-1);
	if (len_fin == (int)ft_strlen(*abuffer))
		return (0);
	else
	{
		if (!(dup_line = ft_strdup(*abuffer + len_fin + 1)))
			return (-1);
		ft_memdel((void**)abuffer);
		*abuffer = dup_line;
		return (1);
	}
}

static int		fill_buffer(const int fd, char **abuffer)
{
	int	ret;

	if (*abuffer != NULL)
		ft_memdel((void**)abuffer);
	if (!(*abuffer = (char*)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	ret = read(fd, *abuffer, BUFF_SIZE);
	(*abuffer)[BUFF_SIZE] = '\0';
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static char		*buffer;
	int				ret_read;
	int				ret_truc;

	if (line == NULL)
		return (-1);
	*line = NULL;
	if (buffer == NULL)
		if ((ret_read = fill_buffer(fd, &buffer)) == -1)
			return (-1);
	if (ft_strlen(buffer) == 0 && (ret_read = fill_buffer(fd, &buffer)) == 0)
		return (0);
	while ((ret_truc = ft_truc(line, &buffer)) == 0)
	{
		if ((ret_read = fill_buffer(fd, &buffer)) == -1)
			return (-1);
		else if (ret_read == 0)
			return (1);
	}
	if (ret_truc == -1 || ret_read == -1)
		return (-1);
	return (1);
}
