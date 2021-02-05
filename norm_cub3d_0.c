/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_cub3d_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:02:21 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/21 10:41:25 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		redbutton(void)
{
	mlx_destroy_window(g_mlx, g_window);
	exit(0);
	return (0);
}

float	distance_btween_point(float x1, float y1, float x2, float y2)
{
	float m;

	m = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
	return (m);
}

int		render_x_s_helf_1(t_sprit *sprit, int dest, int texetofsetx)
{
	if (sprit->point_center_y > sprit->center_y)
	{
		dest = distance_btween_point(sprit->point_center_x,
		sprit->point_center_y, sprit->center_x, sprit->center_y);
		dest = 32 + dest;
		texetofsetx = dest;
	}
	else
	{
		dest = distance_btween_point(sprit->point_center_x,
		sprit->point_center_y, sprit->center_x, sprit->center_y);
		dest = 32 - dest;
		texetofsetx = dest;
	}
	return (texetofsetx);
}

int		render_x_s_helf_2(t_sprit *sprit, int dest, int texetofsetx)
{
	if (sprit->point_center_y < sprit->center_y)
	{
		dest = distance_btween_point(sprit->point_center_x,
		sprit->point_center_y, sprit->center_x, sprit->center_y);
		dest = 32 + dest;
		texetofsetx = dest;
	}
	else
	{
		dest = distance_btween_point(sprit->point_center_x,
		sprit->point_center_y, sprit->center_x, sprit->center_y);
		dest = 32 - dest;
		texetofsetx = dest;
	}
	return (texetofsetx);
}

int		render_x_s_helf_3(t_sprit *sprit, int dest, int texetofsetx)
{
	if (sprit->point_center_x > sprit->center_x)
	{
		dest = distance_btween_point(sprit->point_center_x,
		sprit->point_center_y, sprit->center_x, sprit->center_y);
		dest = 32 - dest;
		texetofsetx = dest;
	}
	else
	{
		dest = distance_btween_point(sprit->point_center_x,
		sprit->point_center_y, sprit->center_x, sprit->center_y);
		dest = 32 + dest;
		texetofsetx = dest;
	}
	return (texetofsetx);
}
