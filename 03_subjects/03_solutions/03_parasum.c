/*
** PARASUM: Write a program that displays the number of arguments passed to it,
** followed by a newline.
*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n / 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

int		main(int ac, char **av)
{
	int count;

	if (ac < 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (av[1])
	{
		count = ac - 1;
		ft_putnbr(count);
		ft_putchar('\n');
	}
	return (0);
}
