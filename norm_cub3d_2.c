/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_cub3d_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:54:00 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 12:19:38 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite_data(t_sprit *tmp, int i)
{
	g_normi.dpp = (g_map.weight / 2) / tan(FOV / 2);
	g_normi.correct_destance = tmp->distance_center *
	cos(g_rays[i].rayangle - g_a);
	g_normi.project = (WALL_SIZE / g_normi.correct_destance) * g_normi.dpp;
	g_normi.wallstriphight = g_normi.project;
	g_normi.walltop = (g_map.height / 2) - (g_normi.wallstriphight / 2);
	g_normi.walltop = g_normi.walltop < 0 ? 0 : g_normi.walltop;
	g_normi.wallbottom = (g_map.height / 2) + (g_normi.wallstriphight / 2);
	g_normi.wallbottom = g_normi.wallbottom > g_map.height ?
	g_map.height : g_normi.wallbottom;
	g_normi.textureofsetx = render_x_s(tmp, i);
	g_normi.y = g_normi.walltop;
}

void	color_sprite(int i)
{
	if (g_normi.color != BLACK)
		g_img_data[(g_map.weight * g_normi.y) + i] = g_texture_sprite_img[(64 *
		g_normi.textureofsety) + g_normi.textureofsetx];
}

void	while_sprite_helf(int i)
{
	while (g_normi.y < g_normi.wallbottom)
	{
		g_normi.distancefromtop = g_normi.y +
		(g_normi.wallstriphight / 2) - (g_map.height / 2);
		g_normi.textureofsety = g_normi.distancefromtop *
		((float)64 / g_normi.wallstriphight);
		g_normi.color = g_texture_sprite_img[(64 * g_normi.textureofsety)
		+ g_normi.textureofsetx];
		color_sprite(i);
		g_normi.y++;
	}
}

void	draw_sprit(int i)
{
	t_sprit *tmp;

	if (g_rays[i].issprit)
	{
		tmp = g_rays[i].sprit;
		while (1)
		{
			draw_sprite_data(tmp, i);
			if (g_normi.textureofsetx >= 0 && g_normi.textureofsetx < WALL_SIZE)
				while_sprite_helf(i);
			if (!tmp->next)
				break ;
			tmp = tmp->next;
		}
	}
}

int		iswall_raycheck(float x, float y)
{
	int	idxx;
	int	idxy;

	idxy = x / WALL_SIZE;
	idxx = y / WALL_SIZE;
	if (idxx < 0 || idxx >= g_map.cols || idxy < 0 || idxy >= g_map.rows)
	{
		return (1);
	}
	return (g_map.map[idxy][idxx] == '1');
}
