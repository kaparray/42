#include <unistd.h>

void	putchr(char a) {
	write(1, &a, 1);
}

void	putnum(int n) {
	while (n < 10)
	{
		putchr(n + '0');
		return ;
	}
	putnum(n / 10);
	putchr((n % 10) + '0');
}

int		main() {

	int i = 1;
	while (i >= 1 && i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else
			putnum(i);
		write(1, "\n", 1);
		i++;
	}

	return (0);
}
