# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 14:02:40 by gmorais-          #+#    #+#              #
#    Updated: 2023/03/24 14:28:07 by gmorais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ${wildcard *.c} ${wildcard ft_printf/*.c} ${wildcard libft/*.c}

NAME = push_swap

OBJS =${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean: 
	@rm -rf ${OBJS}
fclean: clean
	@rm -rf ${NAME}

fclean_all: fclean

re:fclean ${NAME}