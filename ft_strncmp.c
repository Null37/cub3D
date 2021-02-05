/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:00:20 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/18 14:56:00 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
