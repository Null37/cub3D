/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:45:00 by ssamadi           #+#    #+#             */
/*   Updated: 2021/01/18 15:16:07 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

typedef struct
{
	int		r;
	int		ret;
	int		j;
	size_t	i;
	char	*b;
}			t_gnl;

char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *s1, unsigned int start, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			get_next_line(int fd, char **line);
size_t		ft_strlen(char const *str);
char		*ft_strdup(char *s1);

#endif
