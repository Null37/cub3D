/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_cub3d_7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:09:23 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 08:55:58 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	walk_half(void)
{
	float spx;
	float spy;

	spx = g_playerx;
	spy = g_playery;
	g_stopx = g_playerx + g_walkspeed * cos(g_a);
	g_stopy = g_playery + g_walkspeed * sin(g_a);
	if (iswall(g_stopx, g_stopy) == 0)
	{
		g_playerx += g_walkspeed * cos(g_a);
		g_playery += g_walkspeed * sin(g_a);
	}
	else if (iswall(g_stopx, g_stopy) == 1)
	{
		g_playerx = spx;
		g_playery = spy;
	}
}

void	walk(void)
{
	float spx;
	float spy;

	spx = g_playerx;
	spy = g_playery;
	if (g_walkderction == 1 && g_turnface == 0 && g_turnderction == 0)
		walk_half();
	if (g_walkderction == -1 && g_turnface == 0 && g_turnderction == 0)
	{
		g_stopx = g_playerx - g_walkspeed * cos(g_a);
		g_stopy = g_playery - g_walkspeed * sin(g_a);
		if (iswall(g_stopx, g_stopy) == 0)
		{
			g_playerx -= g_walkspeed * cos(g_a);
			g_playery -= g_walkspeed * sin(g_a);
		}
		else if (iswall(g_stopx, g_stopy) == 1)
		{
			g_playerx = spx;
			g_playery = spy;
		}
	}
}

void	half_turn(void)
{
	float spx;
	float spy;

	spx = g_playerx;
	spy = g_playery;
	g_stopx = g_playerx + g_walkspeed * cos(g_a - 0.5 * PI);
	g_stopy = g_playery + g_walkspeed * sin(g_a - 0.5 * PI);
	if (iswall(g_stopx, g_stopy) == 0)
	{
		g_playerx += g_walkspeed * cos(g_a - 0.5 * PI);
		g_playery += g_walkspeed * sin(g_a - 0.5 * PI);
	}
	else if (iswall(g_stopx, g_stopy) == 1)
	{
		g_playerx = spx;
		g_playery = spy;
	}
}

void	turn(void)
{
	float spx;
	float spy;

	spx = g_playerx;
	spy = g_playery;
	if (g_turnderction == -1 && g_turnface == 0 && g_walkderction == 0)
		half_turn();
	if (g_turnderction == 1 && g_turnface == 0 && g_walkderction == 0)
	{
		g_stopx = g_playerx + g_walkspeed * cos(g_a + 0.5 * PI);
		g_stopy = g_playery + g_walkspeed * sin(g_a + 0.5 * PI);
		if (iswall(g_stopx, g_stopy) == 0)
		{
			g_playerx += g_walkspeed * cos(g_a + 0.5 * PI);
			g_playery += g_walkspeed * sin(g_a + 0.5 * PI);
		}
		else if (iswall(g_stopx, g_stopy) == 1)
		{
			g_playerx = spx;
			g_playery = spy;
		}
	}
}

void	texture(void)
{
	g_texture_north = mlx_xpm_file_to_image(g_mlx, g_map.path_no,
	&g_w_texture, &g_h_texture);
	g_texture_south = mlx_xpm_file_to_image(g_mlx, g_map.path_so,
	&g_w_texture, &g_h_texture);
	g_texture_east = mlx_xpm_file_to_image(g_mlx, g_map.path_ea,
	&g_w_texture, &g_h_texture);
	g_texture_west = mlx_xpm_file_to_image(g_mlx, g_map.path_we,
	&g_w_texture, &g_h_texture);
	g_texture_sprite = mlx_xpm_file_to_image(g_mlx, g_map.path_s,
	&g_w_texture, &g_h_texture);
	free_texture();
	check_is_not_null();
	g_texture_north_img = (int *)mlx_get_data_addr(g_texture_north,
	&g_us1, &g_us2, &g_us3);
	g_texture_south_img = (int *)mlx_get_data_addr(g_texture_south,
	&g_us1, &g_us2, &g_us3);
	g_texture_east_img = (int *)mlx_get_data_addr(g_texture_east,
	&g_us1, &g_us2, &g_us3);
	g_texture_west_img = (int *)mlx_get_data_addr(g_texture_west,
	&g_us1, &g_us2, &g_us3);
	g_texture_sprite_img = (int *)mlx_get_data_addr(g_texture_sprite,
	&g_us1, &g_us2, &g_us3);
	check_is_not_null_v2();
}
