
FLAGS = -g -Wall -Wextra -Werror
NAME = fillit
FILES = validation.c\
		reader.c\
		main.c\
		libft/ft_strjoin.c\
		libft/ft_strnew.c\
		libft/get_next_line.c\
		libft/ft_bzero.c\
		libft/ft_strchr.c\
		libft/ft_strdel.c\
		libft/ft_strdup.c\
		libft/ft_strlen.c\
		libft/ft_strsub.c\
		libft/ft_memcpy.c\
		libft/ft_putchar.c\
		libft/ft_putstr.c\
		libft/ft_putendl.c



OBJ = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME):
		clang -o $(NAME) $(FILES) -I fullit.h -L libft/ -lft
		clang $(FLAFS) -I fillit.h  $(FILES)



clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
