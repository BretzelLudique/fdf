/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 04:21:54 by czhang            #+#    #+#             */
/*   Updated: 2019/07/02 05:52:17 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ptit_free(t_tab *tab)
{
	int	i;

	if (!tab)
		return ;
	if (!tab->data)
	{
		free(tab);
		return ;
	}
	i = -1;
	while (++i < tab->y_size && tab->data[i])
		free((tab->data)[i]);
	free(tab);
}

t_tab	*new_tab(void **data, int x_size, int y_size)
{
	t_tab	*tab;

	if (!(tab = (t_tab *)malloc(sizeof(t_tab))))
	{
		ptit_free(tab);
		return (0);
	}
	if (data)
		tab->data = data;
	tab->x_size = x_size;
	tab->y_size = y_size;
	return (tab);
}

int		substract_t_coord(t_tab *tab, t_coord min)
{
	int		x;
	int		y;
	t_coord	**data;

	data = (t_coord **)tab->data;
	x = -1;
	while (++x < tab->x_size)
	{
		y = -1;
		while (++y < tab->y_size)
		{
			data[y][x].x -= min.x;
			data[y][x].y -= min.y;
		}
	}
	return (1);
}

int		divide_t_coord(t_tab *tab, int coeff)
{
	int		x;
	int		y;
	t_coord	**data;

	data = (t_coord **)tab->data;
	x = -1;
	while (++x < tab->x_size)
	{
		y = -1;
		while (++y < tab->y_size)
		{
			data[y][x].x /= coeff;
			data[y][x].y /= coeff;
		}
	}
	return (1);
}
