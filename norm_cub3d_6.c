/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_cub3d_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:17:39 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/21 12:21:31 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	all_equal_zero(void)
{
	g_map.weight = -1;
	g_map.height = -1;
	g_map.g_checkr = NULL;
	g_map.path_no = NULL;
	g_map.path_ea = NULL;
	g_map.path_s = NULL;
	g_map.path_so = NULL;
	g_map.path_we = NULL;
	g_map.string = NULL;
	g_map.save_wnea = NULL;
	g_map.is_r = 0;
	g_map.is_no = 0;
	g_map.is_so = 0;
	g_map.is_we = 0;
	g_map.is_ea = 0;
	g_map.is_s = 0;
	g_map.info_done = 0;
	g_map.now = 0;
	g_map.cols = 0;
	g_save_is = 0;
	g_map.rows = 0;
	g_map.player_ck = -1;
}

void	zall_zero_global(void)
{
	g_walkderction = 0;
	g_walkspeed = 15;
	g_turnspeed = 0.2;
}

void	player_ey(void)
{
	if (g_player_what == 'N')
		g_a = 3 * M_PI / 2;
	if (g_player_what == 'S')
		g_a = M_PI / 2;
	if (g_player_what == 'W')
		g_a = 0;
	if (g_player_what == 'E')
		g_a = M_PI;
	g_a = g_a - M_PI / 2;
}

void	castallray(void)
{
	int		rayid;
	float	rayangle;

	rayid = 0;
	rayangle = g_a + (FOV / 2);
	while (rayid < g_map.weight)
	{
		castray(rayangle, rayid);
		rayangle -= FOV / g_map.weight;
		rayid++;
	}
}
