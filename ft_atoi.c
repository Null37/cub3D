/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:28:32 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/19 07:41:34 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi(const char *str)
{
	unsigned long long int	i;
	unsigned long long int	save;
	unsigned long long int	x;

	x = 1;
	i = 0;
	save = 0;
	while (str[i] == 32 || str[i] == 9 || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' && str[i + 1] != '+')
	{
		x = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		save = save * 10 + (str[i] - 48);
		i++;
	}
	return (save * x);
}
