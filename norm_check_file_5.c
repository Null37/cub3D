/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_check_file_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 08:34:34 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 08:35:08 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_f(char *str, int n_count, char *line)
{
	if (n_count == 0 && ft_strncmp(str, "F", 2) == 0
	&& g_map.g_checkr == NULL && g_map.is_f == 0)
	{
		g_map.g_checkr = "F";
		check_space(line, 1);
	}
	else if (n_count == 0 && ft_strncmp(str, "F", 2) == 0 &&
	g_map.g_checkr == NULL && g_map.is_f == 1)
		my_perror("something wrong\n");
	if (n_count == 1 && ft_strncmp(g_map.g_checkr, "F", 2) == 0)
	{
		skip_c_f(g_map.g_checkr, line);
		if (g_map.is == 3)
			g_map.is_f = 1;
		g_map.g_checkr = NULL;
	}
}

int		norm_helf_check_str(char *lol, char *k, int i)
{
	if (ft_isdigit(lol[i]))
		g_map.is++;
	if (ft_isdigit(lol[i]))
	{
		g_map.number = 1;
		is_str(lol, g_map.is, i, k);
		while (ft_isdigit(lol[i]))
			i++;
	}
	while (lol[i] == 32)
		i++;
	return (i);
}

void	error_helo_norm(void)
{
	if (g_map.fasila > 2 || g_map.fasila < 2 || g_map.is < 3)
		my_perror("something wrong\n");
}

void	norm_l(void)
{
	g_map.number = 0;
	g_map.fasila = 0;
	g_map.is = 0;
	g_i_str = 0;
}

int		check_str(char *lol, char *k)
{
	norm_l();
	while (lol[g_i_str])
	{
		g_i_str = norm_helf_check_str(lol, k, g_i_str);
		if (ft_isdigit(lol[g_i_str]) && g_map.number == 0)
			continue;
		if (lol[g_i_str] == ',')
		{
			g_map.fasila++;
			g_map.number = 0;
			if (lol[g_i_str + 1] != ',')
			{
				g_i_str++;
				continue;
			}
		}
		else if (lol[g_i_str] != ',' && lol[g_i_str] != '\0')
			my_perror("something wrong 1000 \n");
		else if (lol[g_i_str] == '\0')
			break ;
		g_i_str++;
	}
	error_helo_norm();
	return (1);
}
