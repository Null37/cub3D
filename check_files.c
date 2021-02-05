/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:13:59 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 08:44:10 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_n_w_e_s(char *str, int n_count, int o, char *line)
{
	push_string(str);
	if (ft_strncmp(g_map.g_checkr, "NO", 3) == 0 && n_count == 1 && o == 2)
		helf_norm_no(line);
	else if (ft_strncmp(g_map.g_checkr, "WE", 3) == 0 && n_count == 1 && o == 2)
		norm_we_helf(line);
	else if (ft_strncmp(g_map.g_checkr, "SO", 3) == 0 && n_count == 1 && o == 2)
		helf_norm_so(line);
	else if (ft_strncmp(g_map.g_checkr, "EA", 3) == 0 && n_count == 1 && o == 2)
		helf_norm_ea(line);
	else if (ft_strncmp(g_map.g_checkr, "S", 2) == 0 && n_count == 1 && o == 2)
		helf_norm_s(line);
	else if ((o > 2 && ft_strncmp(g_map.g_checkr, "S", 2) == 0) ||
	(o > 2 && ft_strncmp(g_map.g_checkr, "NO", 2) == 0)
	|| (o > 2 && ft_strncmp(g_map.g_checkr, "EA", 2) == 0)
	|| (o > 2 && ft_strncmp(g_map.g_checkr, "WE", 2) == 0)
	|| (o > 2 && ft_strncmp(g_map.g_checkr, "SO", 2) == 0))
		my_perror("should two argmount \n");
}

void	check(char *str, int n_count, int o, char *line)
{
	check_all_all(str, n_count);
	check_r(str, n_count, o, line);
	check_n_w_e_s(str, n_count, o, line);
	check_f(str, n_count, line);
	check_c(str, n_count, line);
	check_space_f_l(line);
	now_or_not();
}

void	map_check(void)
{
	string_valid();
	map_fall();
	is_valid();
}
