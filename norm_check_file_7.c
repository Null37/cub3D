/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_check_file_7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:17:14 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 08:43:22 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	norm_we_helf(char *line)
{
	check_space(line, 2);
	g_map.save_wnea = skip(line, g_map.g_checkr);
	g_map.path_we = ft_strjoin1("", g_map.save_wnea);
	free(g_map.save_wnea);
	g_map.is_we = 1;
	close(g_map.fd);
	g_map.g_checkr = NULL;
}

void	helf_norm_so(char *line)
{
	check_space(line, 2);
	g_map.save_wnea = skip(line, g_map.g_checkr);
	g_map.path_so = ft_strjoin1("", g_map.save_wnea);
	free(g_map.save_wnea);
	g_map.is_so = 1;
	close(g_map.fd);
	g_map.g_checkr = NULL;
}

void	helf_norm_ea(char *line)
{
	check_space(line, 2);
	g_map.save_wnea = skip(line, g_map.g_checkr);
	g_map.path_ea = ft_strjoin1("", g_map.save_wnea);
	free(g_map.save_wnea);
	g_map.is_ea = 1;
	close(g_map.fd);
	g_map.g_checkr = NULL;
}

void	helf_norm_s(char *line)
{
	check_space(line, 2);
	g_map.save_wnea = skip(line, g_map.g_checkr);
	g_map.path_s = ft_strjoin1("", g_map.save_wnea);
	free(g_map.save_wnea);
	g_map.is_s = 1;
	close(g_map.fd);
	g_map.g_checkr = NULL;
}

void	helf_norm_no(char *line)
{
	check_space(line, 2);
	g_map.save_wnea = skip(line, g_map.g_checkr);
	g_map.path_no = ft_strjoin1("", g_map.save_wnea);
	free(g_map.save_wnea);
	g_map.is_no = 1;
	close(g_map.fd);
	g_map.g_checkr = NULL;
}
