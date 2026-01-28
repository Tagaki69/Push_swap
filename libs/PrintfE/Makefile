NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

MANDATORY_NAME = .mandatory

SRCS = ft_itoa_all.c ft_printf.c ft_output.c ft_printf_convertions.c ft_printf_convertions2.c \
ft_string.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@touch $(MANDATORY_NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(MANDATORY_NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re