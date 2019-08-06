#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n / 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int		main(void)
{
	int i = 1;

	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 != 0)
			ft_putstr("fizz");
		else if (i % 5 == 0 && i % 3 != 0)
			ft_putstr("buzz");
		else if (i % 5 == 0 && i % 3 == 0)
			ft_putstr("fizzbuzz");
		else
			ft_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}