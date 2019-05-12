/*
** PRINT_HEX: Write a program that takes a positive (or zero) number expressed in base 10,
** and displays it in base 16 (lowercase letters) followed by a newline.
*/

#include <unistd.h>

int		ft_atoi(char *str)
{
	int num;

	num = 0;
	while (*str)
	{
		num += *str - '0';
		str++;
		if (*str)
			num *= 10;
	}
	return (num);
}

void	print_hex_recursive(int n)
{
	char hex_digits[] = "0123456789abcdef";

	if (n >= 16)
		print_hex_recursive(n / 16);
	write(1, &hex_digits[n % 16], 1);
}

int		main(int ac, char **av)
{
	unsigned int num;

	if (ac == 2)
	{
		num = ft_atoi(av[1]);
		print_hex_recursive(num);
	}
	write(1, "\n", 1);
	return (0);
}
