/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_check_fils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 07:46:34 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/22 12:19:17 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	push_string_v2(char *str)
{
	if (ft_strncmp(str, "SO", 3) == 0 && g_map.g_checkr == NULL
	&& g_map.is_so == 0)
		g_map.g_checkr = "SO";
	else if (ft_strncmp(str, "SO", 3) == 0 && g_map.g_checkr == NULL
	&& g_map.is_so == 1)
		my_perror("something wrong in SO\n");
	else if (ft_strncmp(str, "EA", 3) == 0 && g_map.g_checkr == NULL
	&& g_map.is_ea == 0)
		g_map.g_checkr = "EA";
	else if (ft_strncmp(str, "EA", 3) == 0 && g_map.g_checkr == NULL
	&& g_map.is_ea == 1)
		my_perror("something wrong in EA\n");
	else if (ft_strncmp(str, "S", 2) == 0 && g_map.g_checkr == NULL
	&& g_map.is_s == 0)
		g_map.g_checkr = "S";
	else if (ft_strncmp(str, "S", 2) == 0 && g_map.g_checkr == NULL
	&& g_map.is_s == 1)
		my_perror("something wrong in S\n");
}

char	*ft_strjoin1(char const *s1, char const *s2)
{
	size_t		i;
	size_t		x;
	size_t		j;
	char		*p;

	j = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	x = ft_strlen(s2);
	if (!(p = (char *)malloc((ft_strlen(s1) + x) + 1)))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		p[i] = s1[i];
		i++;
	}
	while (j < x)
	{
		p[i] = s2[j];
		j++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*result;
	int		i;

	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (result)
	{
		ft_strcpy(result, s1);
		ft_strcat(result, s2);
	}
	i = ft_strlen(result);
	result[i] = '\n';
	result[i + 1] = '\0';
	return (result);
}

void	is_str(char *str, int is, int i, char *k)
{
	if (is == 1)
	{
		if (ft_strncmp(k, "F", 2) == 0)
			g_map.red_f = ft_atoi(str + i);
		else if (ft_strncmp(k, "C", 2) == 0)
			g_map.red_c = ft_atoi(str + i);
	}
	else if (is == 2)
	{
		if (ft_strncmp(k, "F", 2) == 0)
			g_map.green_f = ft_atoi(str + i);
		else if (ft_strncmp(k, "C", 2) == 0)
			g_map.green_c = ft_atoi(str + i);
	}
	else if (is == 3)
	{
		if (ft_strncmp(k, "F", 2) == 0)
			g_map.blue_f = ft_atoi(str + i);
		else if (ft_strncmp(k, "C", 2) == 0)
			g_map.blue_c = ft_atoi(str + i);
	}
	else if (is > 3)
		my_perror("something wrong\n");
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
