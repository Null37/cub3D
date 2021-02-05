/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:06:27 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 12:11:40 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	half_game(int nl, char *line)
{
	if (ft_strncmp(g_check_1 + ft_strlen(g_check_1) - 5, "/.cub", 5) == 0)
		my_perror("not *.cub");
	if (ft_strncmp(g_check_1 + ft_strlen(g_check_1) - 4, ".cub", 4) == 0
	&& ft_strlen(g_check_1) > 4)
		helf_get_line(nl, line);
	else
		my_perror("not *.cub");
}

int		main(int argc, char *argv[])
{
	char	*line;
	int		nl;

	line = NULL;
	nl = 0;
	nl = mini_add_2(nl, argv);
	if (argc == 1)
		my_perror("you should be include the map");
	if (argc == 2 || argc == 3)
		half_game(nl, line);
	if (argc > 3)
		my_perror("just 2 argument map and --save");
	if (argc == 3 && ft_strncmp(g_check_2, "--save", ft_strlen(g_check_1)) == 0)
		g_save_is = 1;
	else if (argc == 3 && ft_strncmp(g_check_2,
	"--save", ft_strlen(g_check_1)) != 0)
		my_perror("not --save");
	g_mlx = mlx_init();
	if (g_save_is != 1)
		installwindow();
	start(argc);
}
