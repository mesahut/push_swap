NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_split.c \
		push_swap.c \
		push.c \
		rotate.c \
		sort_func_2.c \
		sort_func.c \
		swap.c \
		utils_cost.c \
		utils_move.c \
		utils_one.c \
		utils_two.c \

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