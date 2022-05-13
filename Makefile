# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 10:06:54 by lsuau             #+#    #+#              #
#    Updated: 2022/05/13 11:12:26 by lsuau            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	cub3D

INC 		=	inc/cub3d.h

SRC			=	main.c \
				data.c

RAY			=	image.c \
				game_init.c \
				minimap.c

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
				ft_sixth.c

SRCS		=	${SRC} \
				${addprefix le_ray/, ${RAY}} \
				${addprefix parsing/, ${PARSING}} \
				${addprefix utils/, ${UTILS}}

OBJS		=	${addprefix objs/, ${SRCS:.c=.o}}

CC			=	gcc
CFLAGS		=	#-Wall -Wextra -Werror

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
