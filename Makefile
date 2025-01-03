# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 10:06:54 by lsuau             #+#    #+#              #
#    Updated: 2022/06/14 13:58:05 by mapontil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	cub3D

INC 		=	inc/cub3d.h

SRC			=	main.c \
				data.c

GAME		=	game_loop.c \
				image_init.c \
				minimap.c \
				movement.c \
				player_minimap.c

GRAPH		=	image.c \
				raycasting.c \
				raycasting_2.c

PARSING		=	parsing.c \
				file_data_extract.c \
				file_map_extract.c \
				map_closed.c \
				file_read.c \
				file_error.c \
				file_error_2.c \
				file_error_3.c

UTILS		= 	error.c \
				stock_1.c \
				stock_2.c \
				stock_3.c

SRCS		=	${SRC} \
				${addprefix game/, ${GAME}} \
				${addprefix graphic/, ${GRAPH}} \
				${addprefix parsing/, ${PARSING}} \
				${addprefix utils/, ${UTILS}}

OBJS		=	${addprefix objs/, ${SRCS:.c=.o}}

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -o3

all:		${NAME}

objs/%.o:	src/%.c ${INC} Makefile
			@mkdir -p $(dir $@)
			${CC} ${CFLAGS} -Imlx -c $< -o $@

${NAME}:	${OBJS} ${INC}
			make -C mlx
			${CC} ${CFLAGS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME} ${OBJS}

clean:
			rm -rf objs/

fclean:		clean
			make -C mlx clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
