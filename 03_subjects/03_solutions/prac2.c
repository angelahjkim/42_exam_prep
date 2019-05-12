#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(char *str)
{
	int num;

	num = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == '+')
		str++;
	while (*str)
	{
		num += *str - '0';
		str++;
		if (*str)
			num *= 10;
	}
	return (num);
}

void	print_hex_recur(int n)
{
	char hex_digits[] = "0123456789abcdef";

	if (n >= 16)
		print_hex_recur(n / 16);
	write(1, &hex_digits[n % 16], 1);
}

int		main(int ac, char **av)
{
	int num;

	if (ac == 2)
	{
		num = ft_atoi(av[1]);
		print_hex_recur(num);
	}
	write(1, "\n", 1);
	return (0);
}
