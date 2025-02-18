NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SRCS =	push.c \
		swap.c \
		rotate.c \
		ft_split.c \
		utils_one.c \
		push_swap.c \
		free_error.c \
		sort_func.c \
		utils_cost.c \
		utils_two.c \
		utils_move.c \
		sort_func_2.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean  