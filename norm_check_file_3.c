/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_check_file_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 08:12:22 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 11:59:56 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_player(void)
{
	g_i_pla = -1;
	while (++g_i_pla < g_map.rows)
	{
		g_j_pl = -1;
		while (++g_j_pl < g_map.cols)
		{
			if ((g_map.map[g_i_pla][g_j_pl] == 'N' && g_map.player_ck == -1)
			|| (g_map.map[g_i_pla][g_j_pl] == 'S' && g_map.player_ck == -1)
			|| (g_map.map[g_i_pla][g_j_pl] == 'E' && g_map.player_ck == -1)
			|| (g_map.map[g_i_pla][g_j_pl] == 'W' && g_map.player_ck == -1))
			{
				g_map.player_ck = 1;
				g_player_what = g_map.map[g_i_pla][g_j_pl];
				g_map.map[g_i_pla][g_j_pl] = '0';
				g_map.player_x = (g_i_pla * WALL_SIZE) + (WALL_SIZE / 2);
				g_map.player_y = (g_j_pl * WALL_SIZE) + (WALL_SIZE / 2);
			}
			else if ((g_map.map[g_i_pla][g_j_pl] == 'N' && g_map.player_ck == 1)
			|| (g_map.map[g_i_pla][g_j_pl] == 'S' && g_map.player_ck == 1)
			|| (g_map.map[g_i_pla][g_j_pl] == 'E' && g_map.player_ck == 1)
			|| (g_map.map[g_i_pla][g_j_pl] == 'W' && g_map.player_ck == 1))
				my_perror("player error");
		}
	}
}

void	add_string(char *line)
{
	int		x;
	char	*tmp;

	x = ft_strlen(line);
	if (x > g_map.cols)
		g_map.cols = x;
	tmp = g_map.string;
	g_map.string = ft_strjoin2(g_map.string, line);
	free(tmp);
	g_map.rows++;
	g_map.width_map = g_map.cols * WALL_SIZE;
	g_map.hieth_map = g_map.rows * WALL_SIZE;
}

int		len_of_line(char **str)
{
	int o;

	o = 0;
	while (*(str + o))
		o++;
	return (o);
}

void	check_all(char *line)
{
	int		o;
	char	**str;
	int		i;

	str = ft_split(line, ' ');
	o = len_of_line(str);
	if (str)
	{
		i = 0;
		check_line_space(line);
		while (*(str + i))
		{
			check(*(str + i), i, o, line);
			i++;
		}
	}
	free_str_1(str, o);
}

void	check_all_all(char *str, int n)
{
	if (n == 0)
	{
		if (ft_strncmp(str, "R", 2) != 0 && ft_strncmp(str, "F", 2) != 0
		&& ft_strncmp(str, "C", 2) != 0 && ft_strncmp(str, "NO", 3) != 0
		&& ft_strncmp(str, "SO", 3) != 0 && ft_strncmp(str, "WE", 3) != 0
		&& ft_strncmp(str, "EA", 3) != 0 && ft_strncmp(str, "S", 2) != 0)
			my_perror("in identifier\n");
		else if (g_map.info_done == 1)
			return ;
	}
}
