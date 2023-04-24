# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 14:02:40 by gmorais-          #+#    #+#              #
#    Updated: 2023/04/24 16:03:04 by gmorais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS		= SRC/lists/list_drenas.c \
		SRC/lists/list_drenas_2.c \
		SRC/moves/operacoes_1.c \
		SRC/moves/operacoes_2.c \
		SRC/moves/operacoes_3.c \
		SRC/algori/sort.c \
		SRC/algori/alg100.c \
		SRC/algori/alg500.c \
		SRC/utils/big_sort_util.c \
		SRC/utils/print_lista.c \
		SRC/utils/sort_drenas.c \
		SRC/errors/error.c \
		SRC/errors/is_digit.c \
		main.c

OBJS	=	${SRCS:.c=.o}


FT_PRINTF = ./ft_printf/libftprintf.a
FT_PRINTF_PATH = ./ft_printf

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

all: ${NAME}

${NAME}: ${OBJS}
		make -C ${FT_PRINTF_PATH}
		${CC} ${CFLAGS} ${OBJS} ${FT_PRINTF} -o ${NAME}

dg:
		@${CC} -Wall -Werror -Wextra -g  ${SRCS} -o ${NAME}

clean:
		@rm -rf ${OBJS}
		@make clean -C ${FT_PRINTF_PATH}

fclean: clean
		@rm -rf ${NAME}
		@make fclean -C ${FT_PRINTF_PATH}

fclean_all: fclean

re: fclean ${NAME}

.PHONY: all clean fclean re