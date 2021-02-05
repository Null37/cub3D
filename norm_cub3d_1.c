/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_cub3d_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:42:25 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 08:47:39 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			render_x_s_helf_4(t_sprit *sprit, int dest, int texetofsetx)
{
	if (sprit->point_center_x > sprit->center_x)
	{
		dest = distance_btween_point(sprit->point_center_x,
	sprit->point_center_y, sprit->center_x, sprit->center_y);
		dest = 32 + dest;
		texetofsetx = dest;
	}
	else
	{
		dest = distance_btween_point(sprit->point_center_x,
		sprit->point_center_y, sprit->center_x, sprit->center_y);
		dest = 32 - dest;
		texetofsetx = dest;
	}
	return (texetofsetx);
}

int			render_x_s(t_sprit *sprit, int i)
{
	int dest;
	int texetofsetx;

	dest = 0;
	texetofsetx = 0;
	if (g_playery >= sprit->center_y - 32 &&
	g_playery <= sprit->center_y + 32 && g_rays[i].g_israyfacingleft)
		texetofsetx = render_x_s_helf_1(sprit, dest, texetofsetx);
	else if (g_playery >= sprit->center_y - 32 &&
	g_playery <= sprit->center_y + 32)
		texetofsetx = render_x_s_helf_2(sprit, dest, texetofsetx);
	else if (g_rays[i].g_israyfacingup)
		texetofsetx = render_x_s_helf_3(sprit, dest, texetofsetx);
	else if (g_rays[i].g_israyfacingdown)
		texetofsetx = render_x_s_helf_4(sprit, dest, texetofsetx);
	return (texetofsetx);
}

t_sprit		*newsprit(void)
{
	t_sprit *sprit;

	sprit = (t_sprit *)malloc(sizeof(t_sprit));
	sprit->next = NULL;
	return (sprit);
}

int			esc(int keycode)
{
	if (keycode == 53)
	{
		mlx_destroy_window(g_mlx, g_window);
		exit(0);
	}
	return (0);
}

void		installwindow(void)
{
	t_t test;

	g_window = mlx_new_window(g_mlx, g_map.weight, g_map.height, "cub3D");
	mlx_key_hook(g_window, esc, &test);
	mlx_hook(g_window, 17, 0, redbutton, (void *)0);
}
