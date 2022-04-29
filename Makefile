# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonkim <wonkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 17:50:22 by wonkim            #+#    #+#              #
#    Updated: 2022/04/24 22:05:55 by wonkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf
BONUS_NAME		= 	fdf_bonus

LIB_DIR			= ./LIBS
MLX_DIR			= $(LIB_DIR)/MLX

SRCS 			=	SRCS/00_main.c\
					SRCS/01_check.c\
					SRCS/02_init.c\
					SRCS/03_parse.c\
					SRCS/04_parse_utils.c\
					SRCS/05_draw.c\
					SRCS/06_draw_utils.c\
					SRCS/07_key_hook.c\
					SRCS/08_utils1.c\
					SRCS/09_utils2.c\
					SRCS/10_utils3.c\
					LIBS/GNL/get_next_line.c\
					LIBS/GNL/get_next_line_utils.c\

OBJ				= $(SRCS:.c=.o)

CC				= gcc
RM				= rm
CFLAGS			= -Wall -Wextra -Werror -g
MLX_FLAGS		= -L./LIBS/MLX -lmlx -framework OpenGL -framework Appkit
RMFLAGS			= -f

all:			$(NAME)

$(NAME):		$(OBJ)
				make -C $(MLX_DIR)
				$(CC) ${CFLAGS} $(MLX_FLAGS) $^ -o $@

$(BONUS_NAME):	$(OBJ)
				make -C $(MLX_DIR)
				$(CC) ${CFLAGS} $(MLX_FLAGS) $^ -o ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
				$(RM) $(RMFLAGS) $(OBJ)

fclean:			clean
				$(RM) $(RMFLAGS) $(NAME)
				$(RM) $(RMFLAGS) $(BONUS_NAME)

re:				fclean all

bonus :			$(BONUS_NAME)

.PHONY:			all clean fclean re
