
NAME = fillit
SRC = main.c\
		ft_seperator.c\
		ft_read.c\
		ft_cheacker.c\
		ft_map_generation.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	gcc $(OBJ) libft/libft.a -I libft -o $(NAME)

%.o: %.c fillit.h
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

# analize: libft/libft.a
# 	gcc -Wall -Wextra -pedantic -Werror -Winit-self -Wunreachable-code -Wformat-y2k -Wformat-nonliteral -Wformat-security -Wformat=2 -Wmissing-include-dirs -Wswitch-default -Wtrigraphs -Wstrict-overflow=5 -Wfloat-equal -Wundef -Wshadow -Wbad-function-cast $(CFLAGS) $(SRC) libft/libft.a -I libft/libft.h -o fillit

libft/libft.a:
	make -C libft

.PHONY: clean fclean all re
