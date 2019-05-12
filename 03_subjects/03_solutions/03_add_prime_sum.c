/*
** ADD PRIME SUM: Write a program that takes a positive integer as argument
** and displays the sum of all prime numbers inferior or equal to it
** followed by a newline. If argument is not positive or there are more than 1
** just display 0 followed by a newline.
*/

#include <unistd.h>

int		is_prime(int num)
{
	int i;

	i = 2;
	while (i < num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_atoi(char *str)
{
	int num;

	num = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == '+')
		str++;
	while (*str)
	{
		num += (*str - '0');
		str++;
		if (*str)
			num *= 10;
	}
	return (num);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int num)
{
	if (num / 10)
	{
		ft_putnbr(num / 10);
		ft_putchar(num % 10 + '0');
	}
	else
		ft_putchar(num + '0');
}

int		main(int ac, char **av)
{
	int num;
	int sum;

	if (ac != 2 || av[1][0] == '-')
	{
		write(1, "0\n", 2);
		return (0);
	}
	else
	{
		num = ft_atoi(av[1]);
		sum = 0;
		while (num > 1)
		{
			if (is_prime(num))
			   sum += num;
			num--;	
		}
		ft_putnbr(sum);
		write(1, "\n", 1);
	}
	return (0);
}
