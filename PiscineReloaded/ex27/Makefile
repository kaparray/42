

NAME = ft_display_file
INC = ft_inc.h
FILE = ft_display_file.c

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror $(FILE) ft_putstr.c -I $(INC) -o $(NAME)

clean:
		rm -f *.o

fclean:
		rm -f $(FILE)

re:
	fclean all
