NAME        = push_swap
BONUS_NAME  = checker
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. -g -Ilibs/libftE -Ilibs/PrintfE

LIBFT_DIR   = libs/libftE
PRINTF_DIR  = libs/PrintfE

COMMON_SRCS = srcs/parsing.c srcs/stack_utils.c srcs/memory.c \
              srcs/swap.c srcs/push.c srcs/rotate.c srcs/rev_rotate.c

PS_SRCS     = srcs/main.c srcs/algo_simple.c srcs/algo_medium.c \
              srcs/algo_complex.c srcs/algo_adaptive.c srcs/bench.c

BONUS_SRCS  = bonus/checker.c bonus/get_next_line.c bonus/get_next_line_utils.c \
              bonus/chk_swap_push.c bonus/chk_rotate.c bonus/chk_rev_rotate.c

PS_OBJS     = $(PS_SRCS:.c=.o) $(COMMON_SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o) $(COMMON_SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(PS_OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(PS_OBJS) -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	rm -rf $(PS_OBJS) $(BONUS_OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re