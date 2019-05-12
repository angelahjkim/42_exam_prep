/*
** TAB MULT: Write a program that displays a number's multiplication table.
*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
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

int		ft_atoi(char *str)
{
	int num = 0;

	if (*str == '+')
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

int		main(int ac, char **av)
{
	int num;
	int results[9];
	char i;
	int j;

	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	num = ft_atoi(av[1]);
	j = 0;
	while (j < 9)
	{
		results[j] = num * (j + 1);
		j++;
	}
	i = '1';
	j = 0;
	while (j < 9)
	{
		ft_putchar(i);
		ft_putstr(" x ");
		ft_putnbr(num);
		ft_putstr(" = ");
		ft_putnbr(results[j]);
		ft_putchar('\n');
		j++;
		i++;
	}

	return (0);
}
