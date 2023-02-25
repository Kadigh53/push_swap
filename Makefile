# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 01:02:26 by aaoutem-          #+#    #+#              #
#    Updated: 2023/02/24 22:52:08 by aaoutem-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h

SRCS = main.c pars.c utils_fs/ft_atoi.c utils_fs/ft_split.c utils_fs/ft_strlen.c \
		utils_fs/ft_substr.c error.c stack/ft_lstadd_front.c stack/ft_lstnew.c \
		stack/a.c stack/ft_lstadd_back.c src/operations.c
 
OBJ_F = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJ_F}
	${CC} ${FLAGS} ${OBJ_F} -o push_swap

%.o : %.c ${HEADER}
	${CC} ${FLAGS} $< -c -o $@

clean :
	${RM} ${OBJ_F}

fclean : clean
	${RM} ${NAME}

re : fclean all

# . PHONY re clean fclean 