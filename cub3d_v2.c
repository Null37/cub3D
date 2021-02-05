/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_v2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 08:35:00 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 11:00:00 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	castray(float rayangle, int rayid)
{
	helf_add_horisntal(rayangle, rayid);
	horizntal(rayid);
	heflf_vertical();
	vertical(rayid);
	complet_raycasting(rayid);
}

int		mini_add_2(int nl, char *argv[])
{
	all_equal_zero();
	zall_zero_global();
	nl = 2;
	g_check_1 = argv[1];
	g_check_2 = argv[2];
	return (nl);
}

void	start(int argc)
{
	texture();
	controller();
	if (argc == 3 && ft_strncmp(g_check_2, "--save", ft_strlen(g_check_1)) == 0)
	{
		g_save_is = 1;
		screen_shot();
		exit(0);
	}
	if (g_save_is != 1)
	{
		mlx_hook(g_window, 2, 0, moveplayer, (void *)0);
		mlx_loop(g_mlx);
	}
}
