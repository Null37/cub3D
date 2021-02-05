/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_cub3d_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:30:58 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/21 11:37:26 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		iswall(float x, float y)
{
	int idxx;
	int idxy;

	idxy = x / WALL_SIZE;
	idxx = y / WALL_SIZE;
	if (idxx < 0 || idxx >= g_map.cols || idxy < 0 || idxy >= g_map.rows)
		return (1);
	return (g_map.map[idxy][idxx] == '1' || g_map.map[idxy][idxx] == 32);
}

int		is_sprit(float x, float y)
{
	int idxx;
	int idxy;

	idxy = x / WALL_SIZE;
	idxx = y / WALL_SIZE;
	if (idxx < 0 || idxx >= g_map.cols || idxy < 0 || idxy >= g_map.rows)
		return (0);
	return (g_map.map[idxy][idxx] == '2');
}

float	normalizerayangle(float angle)
{
	angle = fmod(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

void	free_sprite(int i)
{
	t_sprit *sprit;
	t_sprit *tmp;

	sprit = g_rays[i].sprit;
	while (1)
	{
		if (!sprit)
			return ;
		tmp = sprit;
		if (!sprit->next)
		{
			free(tmp);
			return ;
		}
		sprit = sprit->next;
		free(tmp);
	}
}

void	render_w_s(int i)
{
	t_sprit *sprit;
	t_sprit *tmp;

	if (g_rays[i].issprit)
	{
		sprit = g_rays[i].sprit;
		while (1)
		{
			if (g_rays[i].distance > sprit->distance)
				draw_sprit(i);
			else
			{
				if (!sprit->next)
					return ;
				tmp = sprit;
				g_rays[i].sprit = sprit->next;
				sprit = g_rays[i].sprit;
				free(tmp);
				continue ;
			}
			if (!sprit->next)
				return ;
			sprit = sprit->next;
		}
	}
}
