# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sneyt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 09:59:36 by sneyt             #+#    #+#              #
#    Updated: 2022/04/20 11:32:27 by sneyt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CLFAGS	= -Wall -Werror -Wextra
CC		= gcc
INCS	= includes
SRCS	= srcs/ft_printf.c srcs/ft_printf_cs.c srcs/ft_printf_p.c srcs/ft_printf_di.c srcs/ft_printf_u.c srcs/ft_printf_xX.c srcs/libft_extra1.c srcs/libft_extra2.c
RM		= rm -f
OBJS	= ${SRCS:.c=.o}

.c .o :
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME} : ${OBJS}
		ar -rcs ${NAME} ${OBJS}
		ranlib ${NAME}

all : ${NAME}

clean : 
		${RM} ${OBJS}

fclean : clean
		${RM} ${NAME}	
		
re : fclean all clean
