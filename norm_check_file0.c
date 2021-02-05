/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_check_file0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 07:20:24 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 12:20:23 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_perror(char *str)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	exit(1);
}

void	check_space(char *line, int i)
{
	while (line[i])
	{
		while (line[i] == 32)
			i++;
		if (line[i] == '\0' && line[i - 1] == 32)
			my_perror("space\n");
		if (line[i] != 32 && line[i] != '\0')
			break ;
	}
}

char	*skip(char *str, char *str2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str == NULL || str2 == NULL)
		my_perror("Error");
	while (str[i])
	{
		if (str[i] == str2[j])
		{
			i++;
			j++;
		}
		else if (str[i] == 32)
			i++;
		else
			break ;
	}
	g_map.save_str = ft_strdup(str + i);
	return (g_map.save_str);
}

void	error_n(void)
{
	if (g_map.fd == -1 || g_fd == -1)
	{
		perror("Error\n");
		exit(1);
	}
}

void	push_string(char *str)
{
	if (ft_strncmp(str, "NO", 3) == 0 && g_map.g_checkr == NULL
	&& g_map.is_no == 0)
		g_map.g_checkr = "NO";
	else if (ft_strncmp(str, "NO", 3) == 0 && g_map.g_checkr == NULL
	&& g_map.is_no == 1)
		my_perror("something wrong in NO\n");
	else if (ft_strncmp(str, "WE", 3) == 0 && g_map.g_checkr == NULL
	&& g_map.is_we == 0)
		g_map.g_checkr = "WE";
	else if (ft_strncmp(str, "WE", 3) == 0 && g_map.g_checkr == NULL
	&& g_map.is_we == 1)
		my_perror("something wrong in WE\n");
	push_string_v2(str);
}
