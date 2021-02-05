/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_cub3d_11.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:44:13 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 09:02:26 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	complet_raycasting(int rayid)
{
	g_horizntadestanse = (g_foundhorizantalwallhit) ?
	distance_btween_point(g_playerx, g_playery,
	g_horizontalwallhitx, g_horizontalwallhity) : INT_MAX;
	g_verticaldestanse = (g_foundvertwallhit) ?
	distance_btween_point(g_playerx, g_playery,
	g_vertwallhitx, g_vertwallhity) : INT_MAX;
	if (g_verticaldestanse < g_horizntadestanse)
	{
		g_rays[rayid].distance = g_verticaldestanse;
		g_rays[rayid].wallhitx = g_vertwallhitx;
		g_rays[rayid].wallhity = g_vertwallhity;
		g_rays[rayid].washitvertical = TRUE;
	}
	else
	{
		g_rays[rayid].distance = g_horizntadestanse;
		g_rays[rayid].wallhitx = g_horizontalwallhitx;
		g_rays[rayid].wallhity = g_horizontalwallhity;
		g_rays[rayid].washitvertical = FALSE;
	}
	g_rays[rayid].rayangle = g_rayanglea;
	g_rays[rayid].g_israyfacingdown = g_israyfacingdown;
	g_rays[rayid].g_israyfacingup = g_israyfacingup;
	g_rays[rayid].g_israyfacingleft = g_israyfacingleft;
	g_rays[rayid].israyfacingright = g_israyfacinright;
}

void	helf_move_player(int keycode)
{
	if (keycode == 13)
	{
		g_walkderction = 1;
		g_turnderction = 0;
		g_turnface = 0;
	}
	if (keycode == 1)
	{
		g_walkderction = -1;
		g_turnderction = 0;
		g_turnface = 0;
	}
	if (keycode == 0)
	{
		g_turnderction = 1;
		g_walkderction = 0;
		g_turnface = 0;
	}
	if (keycode == 2)
	{
		g_turnderction = -1;
		g_walkderction = 0;
		g_turnface = 0;
	}
}

int		moveplayer(int keycode)
{
	mlx_clear_window(g_mlx, g_window);
	mlx_destroy_image(g_mlx, g_img);
	if (keycode == 123)
	{
		g_a += g_turnspeed;
		g_turnface = 1;
		g_walkderction = 0;
		g_turnderction = 0;
	}
	if (keycode == 124)
	{
		g_a -= g_turnspeed;
		g_turnface = -1;
		g_walkderction = 0;
		g_turnderction = 0;
	}
	helf_move_player(keycode);
	controller();
	g_turnderction = 0;
	g_walkderction = 0;
	g_turnface = 0;
	return (0);
}

int		helf_line(int nl, char *line)
{
	nl = get_next_line(g_fd, &line);
	if (g_map.now == 0)
		check_all(line);
	if ((g_map.now == 2 && line[0] != '\0') || g_map.now == 3)
	{
		if (g_map.now == 3 && line[0] == '\0')
			my_perror("map not valid 100");
		else
		{
			g_map.now = 3;
			add_string(line);
		}
	}
	free(line);
	if (g_map.now == 1)
	{
		g_map.now = 2;
		g_map.string = ft_strdup("");
	}
	line = NULL;
	return (nl);
}

void	helf_get_line(int nl, char *line)
{
	g_fd = open(g_check_1, O_RDONLY);
	if (g_fd == -1)
		error_n();
	else if (g_fd >= 0)
	{
		while (nl != 0)
			nl = helf_line(nl, line);
	}
	free(line);
	if (g_map.now == 0)
		my_perror("something wrong in file");
	map_check();
	g_playerx = g_map.player_x;
	g_playery = g_map.player_y;
	player_ey();
}
