/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 11:41:59 by ssamadi           #+#    #+#             */
/*   Updated: 2020/12/29 16:02:44 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		checknewline(char **str, char **line, char *buff, size_t *i)
{
	char *temp;

	while (buff[*i] != '\0' && buff[*i] != '\n')
		*i = *i + 1;
	if (buff[*i] == '\n')
	{
		temp = *line;
		*line = ft_strjoin(*line, ft_substr(buff, 0, *i));
		if (*line == NULL)
			return (-1);
		*str = ft_substr(buff, *i + 1, ft_strlen(buff) - *i);
		if (*str == NULL)
			return (-1);
		free(buff);
		free(temp);
		return (1);
	}
	return (2);
}

void	checkback(char **str, char *buff, char **line, size_t *i)
{
	char	*temp;

	temp = *line;
	*line = ft_strjoin(*line, buff);
	free(temp);
	*str = NULL;
	*i = 0;
}

int		ft_ret(char **buff, int i)
{
	if (*buff)
	{
		free(*buff);
		*buff = NULL;
	}
	return (i);
}

int		error(t_gnl s, char **str, char **line)
{
	if ((s.ret = checknewline(str, line, s.b, &s.i)) == 2)
	{
		checkback(str, s.b, line, &s.i);
		if (*line == NULL)
			return (ft_ret(str, -1));
	}
	else if (s.ret == -1)
		return (ft_ret(str, -1));
	else
		return (1);
	return (3);
}

int		get_next_line(int fd, char **line)
{
	t_gnl		s;
	static char *str;

	s.i = 0;
	if ((*line = ft_strdup("")) == NULL)
		return (-1);
	while (1)
	{
		if (str == NULL)
		{
			s.b = malloc(sizeof(char) * (BUFFER_SIZE + 1));
			if ((s.r = read(fd, s.b, BUFFER_SIZE)) == -1
					|| s.r == 0 || s.b == NULL)
				return (ft_ret(&s.b, s.r));
			else
				s.b[s.r] = '\0';
		}
		else
			s.b = str;
		if ((s.j = error(s, &str, line)) < 3)
			return (s.j);
	}
}
