/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:51:11 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 11:39:38 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		file_header(int fd, int file_size, int info)
{
	char header[54];

	ft_bzero(header, 54);
	header[0] = (unsigned int)('B');
	header[1] = (unsigned int)('M');
	header[2] = (unsigned int)(file_size);
	header[3] = (unsigned int)(file_size >> 8);
	header[4] = (unsigned int)(file_size >> 16);
	header[5] = (unsigned int)(file_size >> 24);
	header[10] = (54);
	header[14] = (40);
	header[18] = (unsigned int)(info);
	header[19] = (unsigned int)(info >> 8);
	header[20] = (unsigned int)(info >> 16);
	header[21] = (unsigned int)(info >> 24);
	info = -g_map.weight;
	header[22] = (unsigned int)(info);
	header[23] = (unsigned int)(info >> 8);
	header[24] = (unsigned int)(info >> 16);
	header[25] = (unsigned int)(info >> 24);
	header[26] = (1);
	header[28] = (32);
	write(fd, header, 54);
}

void		write_info(int fd)
{
	char	*data;

	data = (char *)g_img_data;
	write(fd, data, (4 * g_map.weight * g_map.height));
}

void		screen_shot(void)
{
	int		fd;
	int		file_size;
	int		info;

	info = g_map.weight;
	file_size = 14 + 40 * (g_map.weight * g_map.height) * 4;
	fd = open("screenshot.bmp", O_CREAT | O_RDWR | S_IRWXU);
	file_header(fd, file_size, info);
	write_info(fd);
	close(fd);
}
