NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -Iincludes

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = \
	src/parsing/parse_args.c \
	src/parsing/validate.c \
	src/utils/validate_utils.c \
	src/utils/parse_args_utils.c \
	src/utils/sorting_utils.c \
	src/utils/print_bench_utils.c \
	src/utils/main_func_utils.c \
	src/utils/chunk_sort_utils.c \
	src/operations/swap.c \
	src/operations/push.c \
	src/operations/rotate.c \
	src/operations/reverse_rotate.c \
	src/sorting/sort_small.c \
	src/sorting/simple_sort.c \
	src/sorting/chunk_sort.c \
	src/sorting/radix_sort.c \
	src/main.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = \
	bonus/checker_bonus.c \
	bonus/get_next_line_bonus.c \
	bonus/utils_bonus.c \
	src/parsing/parse_args.c \
	src/parsing/validate.c \
	src/utils/validate_utils.c \
	src/utils/parse_args_utils.c \
	src/utils/sorting_utils.c \
	src/operations/swap.c \
	src/operations/push.c \
	src/operations/rotate.c \
	src/operations/reverse_rotate.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)


all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus