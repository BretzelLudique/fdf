/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:03:45 by ccarole           #+#    #+#             */
/*   Updated: 2019/05/18 14:16:03 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_read_file(int fd, char **str)
{
	int				ret;
	char			tmp[BUFF_SIZE + 1];
	char			*ptr;

	if ((ret = read(fd, tmp, BUFF_SIZE)) == 0)
		return (0);
	ptr = *str;
	if (ret < 0)
		return (-1);
	tmp[ret] = '\0';
	if (!(*str = ft_strjoin(*str, tmp)))
		return (-1);
	ft_strdel(&ptr);
	if (*str == '\0')
		return (0);
	return (ret);
}

int					get_line(char **line, char **str)
{
	unsigned int	i;
	char			*ptr;
	char			*tmp;

	ptr = *str;
	i = ft_strlen(*str);
	tmp = ft_strchr(*str, '\n');
	tmp[0] = '\0';
	if (!(*line = ft_strdup(*str)))
		return (-1);
	if (!(*str = ft_strsub(*str, ft_strlen(*line) + 1, (i - ft_strlen(*line)))))
		return (-1);
	ft_strdel(&ptr);
	return (1);
}

int					get_line_eof(char **line, char **str)
{
	if (!(*line = ft_strdup(*str)))
		return (-1);
	ft_strclr(*str);
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static char		*str = 0;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	ret = 1;
	while (ret > 0)
	{
		if ((ft_strchr(str, '\n') != NULL) && str != '\0')
			return (get_line(line, &str));
		if (ft_strchr(str, '\n') == NULL && ret != 0)
		{
			ret = ft_read_file(fd, &str);
			if (ret == 0 && (str == 0 || *str == '\0'))
			{
				ft_strdel(&str);
				return (0);
			}
			if (ft_strchr(str, '\n') == NULL && str && ret == 0)
				return (get_line_eof(line, &str));
			if (ret == -1)
				return (-1);
		}
	}
	return (0);
}
