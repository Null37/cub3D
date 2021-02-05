/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_cub3d_9.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:19:59 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 12:21:24 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		helf_render_sprite(float x, float y)
{
	g_i_s = (int)(x / WALL_SIZE);
	g_j_s = (int)(y / WALL_SIZE);
	g_center_x = (g_i_s * WALL_SIZE) + (WALL_SIZE / 2);
	g_center_y = (g_j_s * WALL_SIZE) + (WALL_SIZE / 2);
}

t_sprit		*mini_add(float x, float y, int rayid, t_sprit *g_tmp)
{
	g_n_sps.b = 0;
	g_tmp = g_rays[rayid].sprit;
	g_n_sps.dist = distance_btween_point(g_playerx, g_playery, x, y);
	return (g_tmp);
}

int			helf_render_ls(float x, float y, int rayid)
{
	if (!g_rays[rayid].sprit)
	{
		g_rays[rayid].sprit = newsprit();
		edit_sprit(rayid, x, y, g_rays[rayid].sprit);
		return (2);
	}
	g_tmp = mini_add(x, y, rayid, g_tmp);
	while (1)
	{
		if (g_tmp->i == g_i_s && g_tmp->j == g_j_s)
		{
			if (g_n_sps.dist <= g_tmp->distance)
				edit_sprit(rayid, x, y, g_tmp);
			return (2);
		}
		if (!g_tmp->next)
			break ;
		g_tmp = g_tmp->next;
	}
	g_tmp = g_rays[rayid].sprit;
	return (0);
}

void		render_sprites(float x, float y, int rayid)
{
	helf_render_sprite(x, y);
	if (helf_render_ls(x, y, rayid) == 2)
		return ;
	if (g_n_sps.dist >= g_tmp->distance)
	{
		g_tmp2 = newsprit();
		edit_sprit(rayid, x, y, g_tmp2);
		g_tmp2->next = g_tmp;
		g_rays[rayid].sprit = g_tmp2;
		return ;
	}
	while (g_tmp->next)
	{
		if (g_n_sps.dist >= g_tmp->next->distance)
		{
			g_tmp2 = newsprit();
			edit_sprit(rayid, x, y, g_tmp2);
			g_tmp2->next = g_tmp->next;
			g_tmp->next = g_tmp2;
			return ;
		}
		g_tmp = g_tmp->next;
	}
	g_tmp->next = newsprit();
	edit_sprit(rayid, x, y, g_tmp->next);
}

char		*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
