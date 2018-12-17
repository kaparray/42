
FLAGS = -Wall -Wextra -Werror
NAME = fillit
FILES = validation.c\
		main.c


OBJ = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		clang -o $(NAME) $(FILES) -I fullit.h -L libft/ -lft

$(OBJ): $(FILES)
		clang $(FLAFS) -I fillit.h  $(FILES) 

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all re
