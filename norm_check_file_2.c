/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_check_file_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 07:56:36 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 08:31:39 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	string_valid(void)
{
	int i;

	i = 0;
	while (g_map.string[i])
	{
		if (g_map.string[i] != '1' && g_map.string[i] != '0'
		&& g_map.string[i] != '2' && g_map.string[i] != 32
		&& g_map.string[i] != 10 && g_map.string[i] != 'N'
		&& g_map.string[i] != 'S' && g_map.string[i] != 'W'
		&& g_map.string[i] != 'E')
			my_perror("not_part_on_the_map");
		else
			i++;
	}
}

void	check_new_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			my_perror("wtf new line");
		i++;
	}
}

void	skip_c_f(char *k, char *line)
{
	char	*sr1;

	sr1 = skip(line, k);
	check_new_line(sr1);
	g_map.number = 0;
	g_map.fasila = 0;
	check_str(sr1, k);
	free(sr1);
	if (g_map.red_f > 255 || g_map.green_f > 255 || g_map.blue_f > 255
	|| g_map.red_c > 255 || g_map.green_c > 255 || g_map.blue_c > 255)
		my_perror("R,G,B should be between 0 and 255\n");
}

void	is_valid(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_map.rows)
	{
		while (j < g_map.cols)
		{
			if (g_map.map[i][j] == '0' || g_map.map[i][j] == '2')
			{
				if (i == 0 || i == g_map.rows - 1 || j == 0 ||
				j == g_map.cols - 1 || g_map.map[i - 1][j] == 32
				|| g_map.map[i][j - 1] == 32 || g_map.map[i][j + 1] == 32
				|| g_map.map[i + 1][j] == 32)
					my_perror("map not valid 700\n");
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (g_map.player_ck == -1)
		my_perror("were is player");
}

void	map_fall(void)
{
	int i;
	int j;
	int k;

	i = -1;
	k = 0;
	g_map.map = malloc(sizeof(char*) * g_map.rows);
	while (++i < g_map.rows)
		g_map.map[i] = malloc(sizeof(char) * g_map.cols + 1);
	i = -1;
	while (++i < g_map.rows)
	{
		j = -1;
		while (++j < g_map.cols)
		{
			if (g_map.string[k] != '\n')
				g_map.map[i][j] = g_map.string[k++];
			else
				g_map.map[i][j] = 32;
		}
		k++;
		g_map.map[i][j] = '\0';
	}
	free(g_map.string);
	check_player();
}
