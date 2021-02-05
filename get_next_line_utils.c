/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:43:34 by ssamadi           #+#    #+#             */
/*   Updated: 2019/12/14 17:13:03 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		x;
	size_t		j;
	size_t		k;
	char		*p;

	j = 0;
	i = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	x = ft_strlen(s2);
	k = ft_strlen(s1);
	if (!(p = (char *)malloc((ft_strlen(s1) + x) + 1)))
		return (NULL);
	while (++i < k)
		p[i] = s1[i];
	while (j < x)
	{
		p[i] = s2[j];
		j++;
		i++;
	}
	p[i] = '\0';
	free(s2);
	return (p);
}

size_t	ft_strlen(char const *str)
{
	size_t	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

int		min(int i, int j)
{
	if (i < j)
		return (i);
	else
		return (j);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	lenmalloc;
	size_t	j;
	char	*m;

	j = start;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		lenmalloc = 0;
	else
		lenmalloc = min(len, ft_strlen(s) - start);
	if (!(m = (char *)malloc(sizeof(char) * lenmalloc + 1)))
		return (NULL);
	while (i < lenmalloc)
	{
		m[i] = s[j];
		i++;
		j++;
	}
	m[i] = '\0';
	return (m);
}

char	*ft_strdup(char *s1)
{
	char	*p;
	int		i;
	int		x;

	x = ft_strlen(s1);
	i = 0;
	if (!(p = (char *)malloc(x + 1 * sizeof(char))))
		return (NULL);
	while (i < x)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
