/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_check_file_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 08:28:33 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 11:29:23 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_line_space(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 32)
			break ;
		while (line[i] == 32)
			i++;
		if (line[i] == '\0')
			my_perror("empty line\n");
	}
}

void	now_or_not(void)
{
	if (g_map.is_c == 1 && g_map.is_f == 1 && g_map.is_no == 1
	&& g_map.is_ea == 1 && g_map.is_r == 1 && g_map.is_so == 1
	&& g_map.is_s == 1 && g_map.is_we == 1)
		g_map.now = 1;
}

void	check_space_f_l(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 32)
			my_perror("space first\n");
		else if (line[i] != 32)
			break ;
	}
}

void	check_if_exists(void)
{
	if (g_map.is_c == 0 || g_map.is_f == 0 || g_map.is_no == 0
	|| g_map.is_ea == 0 || g_map.is_r == 0 || g_map.is_so == 0
	|| g_map.is_s == 0 || g_map.is_we == 0)
		my_perror("no identifier or information\n");
	else if (g_map.is_c == 1 && g_map.is_f == 1 && g_map.is_no == 1
	&& g_map.is_ea == 1 && g_map.is_r == 1 && g_map.is_so == 1
	&& g_map.is_s == 1 && g_map.is_we == 1)
		g_map.info_done = 1;
}

void	check_c(char *str, int n_count, char *line)
{
	if (n_count == 0 && ft_strncmp(str, "C", 2) == 0
	&& g_map.g_checkr == NULL && g_map.is_c == 0)
	{
		g_map.g_checkr = "C";
		check_space(line, 1);
	}
	else if (n_count == 0 && ft_strncmp(str, "C", 2) == 0
	&& g_map.g_checkr == NULL && g_map.is_c == 1)
		my_perror("something wrong");
	if (n_count == 1 && ft_strncmp(g_map.g_checkr, "C", 2) == 0)
	{
		skip_c_f(g_map.g_checkr, line);
		if (g_map.is == 3)
			g_map.is_c = 1;
		g_map.g_checkr = NULL;
	}
}
