clang -Wall -Wextra -Werror -I libft/ -o main.o -c main.c
clang -Wall -Wextra -Werror -I libft/ -o validation.o -c validation.c
clang -o a.out main.o validation.o -I fillit.h -L libft/  -lft
