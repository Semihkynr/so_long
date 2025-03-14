NAME = libftprintf.a

SRCS = ft_printf.c			\
		ft_print_char.c		\
		ft_print_hexa.c		\
		ft_print_int.c		\
		ft_print_nbr.c		\
		ft_print_str.c		\
		ft_print_ptr.c		\

		
OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 