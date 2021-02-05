/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_cub3d_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:03:23 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/21 12:07:49 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	build_add(int i)
{
	g_3d.distanceprojectplan = (g_map.weight / 2) / tan(FOV / 2);
	g_3d.correct_destance = g_rays[i].distance * cos(g_rays[i].rayangle - g_a);
	g_3d.project = (WALL_SIZE / g_3d.correct_destance)
	* g_3d.distanceprojectplan;
	g_3d.wallstriphight = g_3d.project;
	g_3d.walltop = (g_map.height / 2) - (g_3d.wallstriphight / 2);
	g_3d.walltop = g_3d.walltop < 0 ? 0 : g_3d.walltop;
	g_3d.wallbottom = (g_map.height / 2) + (g_3d.wallstriphight / 2);
	g_3d.wallbottom = g_3d.wallbottom > g_map.height ?
	g_map.height : g_3d.wallbottom;
	g_3d.b = 0;
}

void	half_build_3d_i(int i)
{
	while (g_3d.b < g_3d.walltop)
	{
		g_img_data[(g_map.weight * g_3d.b) + i] = ((g_map.red_c * 256 * 256)
		+ (g_map.green_c * 256) + g_map.blue_c);
		g_3d.b++;
	}
	g_3d.y = g_3d.walltop;
	if (g_rays[i].washitvertical == TRUE)
		g_3d.textureofsetx = (int)g_rays[i].wallhity % g_h_texture;
	else
		g_3d.textureofsetx = (int)g_rays[i].wallhitx % g_w_texture;
	if (g_rays[i].g_israyfacingup && g_rays[i].washitvertical == FALSE)
	{
		while (g_3d.y < g_3d.wallbottom)
		{
			g_3d.distancefromtop = g_3d.y + (g_3d.wallstriphight / 2)
			- (g_map.height / 2);
			g_3d.textureofsety = g_3d.distancefromtop * ((float)g_h_texture /
			g_3d.wallstriphight);
			g_img_data[(g_map.weight * g_3d.y) + i] = g_texture_east_img[(
			g_h_texture * g_3d.textureofsety) + g_3d.textureofsetx];
			g_3d.y++;
		}
	}
}

void	hel_build_3d_2(int i)
{
	if (g_rays[i].g_israyfacingdown && g_rays[i].washitvertical == FALSE)
		while (g_3d.y < g_3d.wallbottom)
		{
			g_3d.distancefromtop = g_3d.y + (g_3d.wallstriphight / 2)
			- (g_map.height / 2);
			g_3d.textureofsety = g_3d.distancefromtop *
			((float)g_h_texture / g_3d.wallstriphight);
			g_img_data[(g_map.weight * g_3d.y) + i] = g_texture_west_img[(
			g_h_texture * g_3d.textureofsety) + g_3d.textureofsetx];
			g_3d.y++;
		}
	if (g_rays[i].israyfacingright && g_rays[i].washitvertical == TRUE)
	{
		while (g_3d.y < g_3d.wallbottom)
		{
			g_3d.distancefromtop = g_3d.y + (g_3d.wallstriphight / 2)
			- (g_map.height / 2);
			g_3d.textureofsety = g_3d.distancefromtop * ((float)g_h_texture
			/ g_3d.wallstriphight);
			g_img_data[(g_map.weight * g_3d.y) + i] = g_texture_north_img[(
				g_h_texture * g_3d.textureofsety) + g_3d.textureofsetx];
			g_3d.y++;
		}
	}
}

void	last_build_3d_3(int i)
{
	if (g_rays[i].g_israyfacingleft && g_rays[i].washitvertical == TRUE)
	{
		while (g_3d.y < g_3d.wallbottom)
		{
			g_3d.distancefromtop = g_3d.y + (g_3d.wallstriphight / 2)
			- (g_map.height / 2);
			g_3d.textureofsety = g_3d.distancefromtop * ((float)g_h_texture
			/ g_3d.wallstriphight);
			g_img_data[(g_map.weight * g_3d.y) + i] = g_texture_south_img[(
				g_h_texture * g_3d.textureofsety) + g_3d.textureofsetx];
			g_3d.y++;
		}
	}
	g_3d.c = g_3d.wallbottom;
	while (g_3d.c < g_map.height)
	{
		g_img_data[(g_map.weight * g_3d.c) + i] = ((g_map.red_f * 256 * 256)
		+ (g_map.green_f * 256) + g_map.blue_f);
		g_3d.c++;
	}
}

void	build_3d(void)
{
	int i;

	i = 0;
	while (i < g_map.weight)
	{
		build_add(i);
		half_build_3d_i(i);
		hel_build_3d_2(i);
		last_build_3d_3(i);
		render_w_s(i);
		free_sprite(i);
		i++;
	}
}
