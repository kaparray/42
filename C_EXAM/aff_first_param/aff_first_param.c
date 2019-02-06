#include <unistd.h>


void ft_print_string(char *str) {
	int i = 0;
	while (str[i] != 0) {
		write(1, &(str[i]), 1);
		i++;
	}
}

int		main(int ac, char **av) {

	if (ac > 1)
		ft_print_string(av[1]);
	write(1, "\n", 1);

	return (0);
}
