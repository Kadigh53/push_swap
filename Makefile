# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 01:02:26 by aaoutem-          #+#    #+#              #
#    Updated: 2023/04/02 00:47:52 by aaoutem-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -rf
FLAGS = -Wall -Wextra 
HEADER = push_swap.h

SRCS = main.c pars.c utils_fs/ft_atoi.c utils_fs/ft_split.c utils_fs/ft_strlen.c \
		utils_fs/ft_substr.c error.c stack/ft_lstadd_front.c stack/ft_lstnew.c \
		stack/stack_construction.c stack/ft_lstadd_back.c LIS.c LIS2.c src/operations.c \
		src/ft_putstr.c sort.c sort_action.c three_case.c

BONUS = bonus/checker_bonus.c \
	bonus/pars_bonus.c bonus/error.c \
	bonus/sort_check.c \
	bonus/src/ft_putstr.c \
	bonus/src/operations.c \
	bonus/stack/ft_lstadd_back.c \
	bonus/stack/stack_construction.c\
	bonus/stack/ft_lstnew.c \
	bonus/stack/ft_lstlast.c \
	bonus/stack/ft_lstadd_front.c \
	bonus/util_fcts_bonus/ft_atoi.c \
	bonus/util_fcts_bonus/ft_split.c \
	bonus/util_fcts_bonus/ft_strlen.c\
	bonus/util_fcts_bonus/ft_strjoin.c \
	bonus/util_fcts_bonus/ft_strncmp.c \
	bonus/util_fcts_bonus/ft_substr.c \

OBJ_F = ${SRCS:.c=.o}

BONUS_OBJF = ${BONUS:.c=.o}

all : ${NAME}

${NAME} : ${OBJ_F}
	${CC} ${FLAGS} ${OBJ_F} -o push_swap

bonus : ${BONUS_OBJF} ${HEADER}
	${CC} ${FLAGS} ${BONUS_OBJF} -o checker

%.o : %.c ${HEADER}
	${CC} ${FLAGS} $< -c -o $@

clean :
	${RM} ${OBJ_F} ${BONUS_OBJF}

fclean : clean
	${RM} ${NAME}

re : fclean all

# . PHONY re clean fclean 