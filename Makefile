NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar crs
RM = rm -f

SRC = \
ft_put_base.c \
ft_putstr.c \
ft_putnbr.c \
ft_putnbr_unsigned.c \
ft_putchar.c \
ft_parse.c \
ft_printf.c \



OBJ = $(SRC:.c=.o)

all: $(NAME)
clean:
	$(RM) $(OBJ) $(OBJB)
fclean:clean
	$(RM) $(NAME)
re:fclean all

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus