/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 04:21:54 by czhang            #+#    #+#             */
/*   Updated: 2019/09/02 14:45:00 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ptit_free(t_tab *tab)
{
	if (!tab)
		return ;
	if (!tab->data)
	{
		ft_memdel((void**)&tab);
		return ;
	}
	while (tab->y_size--)
		ft_memdel((void**)&(tab->data[tab->y_size]));
	ft_memdel((void**)&(tab->data));
	ft_memdel((void**)&tab);
}

int		reterr_xsize(void)
{
	ft_putendl_fd("Found wrong line length. Exiting.", 2);
	return (0);
}

t_tab	*new_tab(int x_size, int y_size)
{
	t_tab	*tab;

	if (!(tab = (t_tab *)ft_memalloc(sizeof(t_tab))))
	{
		ptit_free(tab);
		return (0);
	}
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

int		divide_t_coord(t_tab *tab, double coeff)
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
