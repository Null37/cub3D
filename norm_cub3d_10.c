/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_cub3d_10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:10:30 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 09:00:26 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	helf_hori(void)
{
	g_verthitsprites_y = 0;
	g_israyfacingdown = g_rayanglea > 0 && g_rayanglea < PI;
	g_israyfacingup = !g_israyfacingdown;
	g_israyfacinright = g_rayanglea < 0.5 * PI || g_rayanglea > 1.5 * PI;
	g_israyfacingleft = !g_israyfacinright;
	g_yintercept = (int)(g_playery / WALL_SIZE) * WALL_SIZE;
	g_yintercept += g_israyfacingdown ? WALL_SIZE : 0;
	g_xintercept = g_playerx + (g_yintercept - g_playery) / tan(g_rayanglea);
	g_ystep = WALL_SIZE;
	g_ystep *= g_israyfacingup ? -1 : 1;
	g_xstep = g_ystep / tan(g_rayanglea);
	g_xstep *= (g_israyfacingleft && g_xstep > 0) ? -1 : 1;
	g_xstep *= (g_israyfacinright && g_xstep < 0) ? -1 : 1;
	g_newhorizantalx = g_xintercept;
	g_newhorizantaly = g_yintercept;
	g_foundhorizantalwallhit = FALSE;
}

void	helf_add_horisntal(float rayangle, int rayid)
{
	g_rays[rayid].sprit = NULL;
	g_rays[rayid].issprit = 0;
	g_rayanglea = normalizerayangle(rayangle);
	g_rays[rayid].rayangle = g_rayanglea;
	g_xstep = 0;
	g_ystep = 0;
	g_xintercept = 0;
	g_yintercept = 0;
	g_horizntadestanse = 0;
	g_verticaldestanse = 0;
	g_newhorizantalx = 0;
	g_newhorizantaly = 0;
	g_foundhorizantalwallhit = 0;
	g_foundvertwallhit = 0;
	g_vertwallhitx = 0;
	g_vertwallhity = 0;
	g_newvertx = 0;
	g_newverty = 0;
	g_horizontalwallhitx = 0;
	g_horizontalwallhity = 0;
	g_horhitsprites_x = 0;
	g_horhitsprites_y = 0;
	g_verthitsprites_x = 0;
	helf_hori();
}

void	horizntal(int rayid)
{
	while (1)
	{
		g_xtocheck = g_newhorizantalx;
		g_ytocheck = g_newhorizantaly + (g_israyfacingup ? -1 : 0);
		if (is_sprit(g_xtocheck, g_ytocheck) == 1)
		{
			g_rays[rayid].issprit = 1;
			g_horhitsprites_x = g_xtocheck;
			g_horhitsprites_y = g_ytocheck;
			g_is_vertical = 0;
			render_sprites(g_xtocheck, g_ytocheck, rayid);
		}
		if (iswall_raycheck(g_xtocheck, g_ytocheck) == 1)
		{
			g_foundhorizantalwallhit = TRUE;
			g_horizontalwallhitx = g_newhorizantalx;
			g_horizontalwallhity = g_newhorizantaly;
			break ;
		}
		else
			g_newhorizantalx += g_xstep;
		g_newhorizantaly += g_ystep;
	}
}

void	heflf_vertical(void)
{
	g_vertwallhitx = 0;
	g_vertwallhity = 0;
	g_xintercept = (int)(g_playerx / WALL_SIZE) * WALL_SIZE;
	g_xintercept += g_israyfacinright ? WALL_SIZE : 0;
	g_yintercept = g_playery + (g_xintercept - g_playerx) * tan(g_rayanglea);
	g_xstep = WALL_SIZE;
	g_xstep *= g_israyfacingleft ? -1 : 1;
	g_ystep = g_ystep * tan(g_rayanglea);
	g_ystep *= (g_israyfacingup && g_ystep > 0) ? -1 : 1;
	g_ystep *= (g_israyfacingdown && g_ystep < 0) ? -1 : 1;
	g_newvertx = g_xintercept;
	g_newverty = g_yintercept;
	g_foundvertwallhit = FALSE;
}

void	vertical(int rayid)
{
	while (1)
	{
		g_xtocheckv = g_newvertx + (g_israyfacingleft ? -1 : 0);
		g_ytocheckv = g_newverty;
		if (is_sprit(g_xtocheckv, g_ytocheckv) == 1)
		{
			g_rays[rayid].issprit = 1;
			g_verthitsprites_x = g_xtocheckv;
			g_verthitsprites_y = g_ytocheckv;
			g_is_vertical = 1;
			render_sprites(g_verthitsprites_x, g_verthitsprites_y, rayid);
		}
		if (iswall_raycheck(g_xtocheckv, g_ytocheckv) == 1)
		{
			g_foundvertwallhit = TRUE;
			g_vertwallhitx = g_newvertx;
			g_vertwallhity = g_newverty;
			break ;
		}
		else
			g_newvertx += g_xstep;
		g_newverty += g_ystep;
	}
}
