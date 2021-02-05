/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_cub3d_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:09:55 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/21 12:14:21 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	edit_sprit(int rayid, float x, float y, t_sprit *sprit)
{
	sprit->is_vertical = g_is_vertical;
	sprit->i = g_i_s;
	sprit->j = g_j_s;
	sprit->center_x = g_center_x;
	sprit->center_y = g_center_y;
	sprit->hitsprites_x = x;
	sprit->hitsprites_y = y;
	sprit->distance = distance_btween_point(g_playerx, g_playery, x, y);
	sprit->distance_center = distance_btween_point(g_playerx, g_playery
	, g_center_x, g_center_y);
	sprit->point_center_x = g_playerx + (cos(g_rays[rayid].rayangle)
	* sprit->distance_center);
	sprit->point_center_y = g_playery + (sin(g_rays[rayid].rayangle)
	* sprit->distance_center);
}

void	check_is_not_null(void)
{
	if (g_texture_north == NULL || g_texture_east == NULL ||
	g_texture_south == NULL || g_texture_west == NULL
	|| g_texture_sprite == NULL)
		my_perror("In texture");
}

void	check_is_not_null_v2(void)
{
	if (g_texture_north_img == NULL || g_texture_east_img == NULL ||
	g_texture_south_img == NULL || g_texture_west_img == NULL
	|| g_texture_sprite_img == NULL)
		my_perror("In texture img");
}

void	free_texture(void)
{
	free(g_map.path_no);
	free(g_map.path_ea);
	free(g_map.path_s);
	free(g_map.path_we);
	free(g_map.path_so);
}

int		controller(void)
{
	g_img = mlx_new_image(g_mlx, g_map.weight, g_map.height);
	g_img_data = (int *)mlx_get_data_addr(g_img, &g_bpp,
	&g_size_line, &g_endian);
	turn();
	walk();
	castallray();
	build_3d();
	if (g_save_is != 1)
		mlx_put_image_to_window(g_mlx, g_window, g_img, 0, 0);
	return (0);
}
