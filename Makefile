SRCS = 	main.c \
		checkerrors.c \
		sort_operations/sorto_print.c sort_operations/sorto_utils.c sort_operations/sorto.c \
		sort_algo/algo_utils.c sort_algo/algo00.c sort_algo/algo01.c \
		sort_algo/push_a_to_b.c sort_algo/push_b_to_a.c sort_algo/simplified.c

OBJDIR = objects
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
OBJS_BONNUS = $(SRCS_BONNUS:%.c=$(OBJDIR)/%.o)
LIB = make -C ./libft
PRINTF = make -C ./printf
INCS = includes
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

all: ${NAME}

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR) $(OBJDIR)/sort_algo $(OBJDIR)/sort_operations 
	@${CC} ${CFLAGS} -I ${INCS} -c $< -o $@

${NAME}: ${OBJS}
	@${LIB}
	@${PRINTF}
	@${CC} ${CFLAGS} -g ${OBJS} -L./libft -lft -L./printf -lftprintf -o ${NAME}

clean:
	@${RM} -r ${OBJDIR}
	@make clean -C ./libft
	@make clean -C ./printf

fclean: clean
	@${RM} ${NAME}
	@make fclean -C ./libft 
	@make fclean -C ./printf

re: fclean all

.PHONY: all clean fclean re
