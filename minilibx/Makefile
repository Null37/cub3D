# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/22 14:57:08 by ssamadi           #+#    #+#              #
#    Updated: 2021/01/22 14:57:14 by ssamadi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC= interface.swift
OBJ=$(SRC:.swift=.o)


NAME=libmlx.dylib

INC=-I.


all: $(NAME)

$(NAME): $(OBJ)
	swiftc $(INC) -o $(NAME) -emit-library $(OBJ) -lz



%.o: %.swift
	swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@
clean:
	rm -f $(NAME) $(OBJ) *.swiftdoc *~

