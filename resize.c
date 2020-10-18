/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 01:22:13 by czhang            #+#    #+#             */
/*   Updated: 2019/09/19 03:48:50 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_coord		*update_range(t_tab *iso)
{
	static t_coord	range[2];
	int				x;
	int				y;
	t_coord			**data;

	data = (t_coord **)iso->data;
	range[0].x = 0;
	range[0].y = 0;
	range[1].x = 0;
	range[1].y = 0;
	x = -1;
	while (++x < iso->x_size)
	{
		y = -1;
		while (++y < iso->y_size)
		{
			range[0].x = range[0].x < data[y][x].x ? range[0].x : data[y][x].x;
			range[0].y = range[0].y < data[y][x].y ? range[0].y : data[y][x].y;
			range[1].x = range[1].x > data[y][x].x ? range[1].x : data[y][x].x;
			range[1].y = range[1].y > data[y][x].y ? range[1].y : data[y][x].y;
		}
	}
	return (range);
}

static int	reduce_coord(t_tab *iso, t_coord range[2])
{
	double coeff;

	coeff = (double)range[1].x / WIDTH;
	if (coeff < (double)range[1].y / HEIGHT)
		coeff = (double)range[1].y / HEIGHT;
	coeff = coeff - (int)coeff == 1 ? (int)coeff : (int)coeff + 1;
	divide_t_coord(iso, coeff);
	update_range(iso);
	return (1);
}

static int	extend_coord(t_tab *iso, t_coord range[2])
{
	double	coeff;

	coeff = (double)WIDTH / range[1].x;
	if (coeff < (double)HEIGHT / range[1].y)
		coeff = (double)HEIGHT / range[1].y;
	coeff = coeff - (int)coeff == 1 ? (int)coeff : (int)coeff - 1;
	divide_t_coord(iso, 1 / (0.8 * coeff));
	update_range(iso);
	return (1);
}

int			resize_coord(t_tab *iso, t_coord range[2])
{
	substract_t_coord(iso, range[0]);
	update_range(iso);
	if (range[1].x > WIDTH || range[1].y > HEIGHT)
		return (reduce_coord(iso, range));
	if ((double)WIDTH / range[1].x > 2 && (double)HEIGHT / range[1].y > 2)
		return (extend_coord(iso, range));
	return (1);
}
