# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 11:43:13 by marlonco          #+#    #+#              #
#    Updated: 2024/05/07 15:22:01 by marlonco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 	libftprintf.a

CC 				= 	gcc

CFLAGS 			= 	-Wall -Wextra -Werror

RM 				= 	rm -f


SRC				= 	srcs/ft_hexa.c srcs/ft_printf.c \
					srcs/ft_unsigned.c srcs/ft_putptr.c srcs/utils.c
	
OBJS 			= 	${SRC:.c=.o}

LIBFT 			=	libft/libft.a

.c.o :
				${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

all: 			${NAME}

${NAME}:		${OBJS}
				make  all -C ./libft
				cp	${LIBFT} ${NAME}
				ar -rcs ${NAME} ${OBJS} $(libft)

lib:
	make all -C ./libft
	make clean -C ./libft

clean:			
				make clean -C ./libft 
				${RM} ${OBJS} ${LIBFT} ${NAME}

fclean: 		clean
				make fclean -C ./libft
				${RM} ${NAME}

re: 			fclean all
 
.PHONY: 		all, clean, fclean, re