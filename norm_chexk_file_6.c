/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_chexk_file_6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:01:58 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 08:37:57 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	len_number(char *str)
{
	unsigned long long int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+')
			i++;
		if (str[i] == '0')
			i++;
		while (ft_isdigit(str[i]))
		{
			g_map.len++;
			i++;
		}
		if (str[i] == '\0')
			break ;
	}
}

void	nor_check_r(char *str1, int n_count)
{
	if (n_count == 1 && g_map.weight == -1)
	{
		g_xxxx = 0;
		if (str1[0] == '+')
			g_xxxx++;
		while (str1[g_xxxx])
		{
			if (ft_isdigit(str1[g_xxxx]))
				g_xxxx++;
			else
				my_perror("resolution\n");
		}
		g_map.len = 0;
		len_number(str1);
		if (g_map.len <= 4)
		{
			g_map.weight = ft_atoi(str1);
			if (g_map.len == 4 && g_map.weight > g_max_r_x)
				g_map.weight = g_max_r_x;
		}
		else if (g_map.len > 4)
			g_map.weight = g_max_r_x;
	}
}

void	norm_2_check_r(char *str1, int n_count)
{
	if (n_count == 2 && g_map.height == -1)
	{
		g_xxxx = 0;
		if (str1[0] == '+')
			g_xxxx++;
		while (str1[g_xxxx])
		{
			if (ft_isdigit(str1[g_xxxx]))
				g_xxxx++;
			else
				my_perror("resolution\n");
		}
		g_map.len = 0;
		len_number(str1);
		if (g_map.len <= 4)
		{
			g_map.height = ft_atoi(str1);
			if (g_map.len == 4 && g_map.height > g_max_r_y)
				g_map.height = g_max_r_y;
		}
		else if (g_map.len > 4)
			g_map.height = g_max_r_y;
		g_map.g_checkr = NULL;
	}
}

void	check_r(char *str1, int n_count, int o, char *line)
{
	mlx_get_screen_size(g_mlx, &g_max_r_x, &g_max_r_y);
	if (ft_strncmp(str1, "R", 2) == 0 &&
	g_map.g_checkr == NULL && g_map.is_r == 0)
	{
		g_map.g_checkr = "R";
		check_space(line, 1);
	}
	else if (ft_strncmp(str1, "R", 2) == 0 &&
	g_map.g_checkr == NULL && g_map.is_r == 1)
		my_perror("something wrong in R\n");
	if (ft_strncmp(g_map.g_checkr, "R", 2) == 0 && g_map.height == -1 && o == 3)
	{
		g_map.is_r = 1;
		nor_check_r(str1, n_count);
		norm_2_check_r(str1, n_count);
	}
	else if (ft_strncmp(g_map.g_checkr, "R", 2) == 0
	&& g_map.height == -1 && o > 3)
		my_perror("resolution\n");
}
