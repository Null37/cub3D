# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 11:38:20 by ssamadi           #+#    #+#              #
#    Updated: 2021/01/22 15:16:07 by ssamadi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FLAGS_MINI = -lmlx -framework OpenGL -framework AppKit -I./minilibx libmlx.dylib -Wall -Wextra -Werror

SRC = cub3d_v2.c\
	get_next_line.c\
	ft_strncmp.c\
	check_files.c\
	ft_atoi.c\
	ft_isdigit.c\
	ft_putstr.c\
	ft_split.c\
	ft_strtrim.c\
	norm_check_file0.c\
	norm_check_fils_1.c\
	norm_check_file_2.c\
	norm_check_file_3.c\
	norm_check_file_4.c\
	norm_check_file_5.c\
	norm_chexk_file_6.c\
	norm_check_file_7.c\
	norm_check_file_8.c\
	screenshot.c\
	ft_bzero.c\
	norm_cub3d_0.c\
	norm_cub3d_1.c\
	norm_cub3d_2.c\
	norm_cub3d_3.c\
	norm_cub3d_4.c\
	norm_cub3d_5.c\
	norm_cub3d_6.c\
	norm_cub3d_7.c\
	norm_cub3d_9.c\
	norm_cub3d_10.c\
	norm_cub3d_11.c\
	get_next_line_utils.c\
	game.c

OBJECTS = $(SRC:.c=.o)

CC = gcc

all: mlxmake $(NAME)

$(NAME): $(SRC)
	@cp ./minilibx/libmlx.dylib .
	@$(CC) $(FLAGS_MINI) $(SRC) -o $(NAME)
mlxmake:
	@$(MAKE)	-C minilibx	
clean: mlxclean
	@rm -fr $(OBJECTS) libmlx.dylib

mlxclean:
	$(MAKE)	-C minilibx	clean

fclean: clean
	@rm -fr $(NAME)

re: fclean all

