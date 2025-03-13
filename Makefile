NAME = so_long

SRCS = slmain.c mapctl.c checkmapctl.c \
	get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

FT_PRİNTF_LIB = ft_printf/libftprintf.a

MLX_LIB = mlx/libmlx.a

MLX_FLAGS = -Lmlx -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm -lbsd

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make -C mlx
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(FT_PRİNTF_LIB) $(MLX_LIB) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C mlx
	make clean -C ft_printf

fclean: clean
	rm -f $(NAME)
	make fclean -C ft_printf


re: fclean all

.PHONY: all clean fclean re
