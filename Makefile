NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. -g -Ilibs/libftE -Ilibs/PrintfE

LIBFT_DIR   = libs/libftE
PRINTF_DIR  = libs/PrintfE

SRCS        = srcs/main.c srcs/parsing.c srcs/swap.c \
              srcs/push.c srcs/rotate.c srcs/rev_rotate.c \
			  srcs/algo.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re