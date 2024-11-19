CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCC = get_next_line.c get_next_line_utils.c
OBJ = $(SRCC:.c=.o)
NAME = libftprintf.a
INCLUDE = includes/ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
