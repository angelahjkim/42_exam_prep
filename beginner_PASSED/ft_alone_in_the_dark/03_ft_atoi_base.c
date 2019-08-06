int		test_base(const char c)
{
	int		nb;

	if (c >= '0' && c <= '9')
		nb = c - '0';
	else if (c >= 'a' && c <= 'z')
		nb = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		nb = c - 'A' + 10;
	else
		nb = -1;
	return (nb);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int		neg;
	int		nb;
	int		current;

	nb = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\f' || *str == '\r' || *str == '\v')
		str++;
	neg = (*str == '-' ? 1 : 0);
	if (*str == '-' || *str == '+')

		str++;

	current = test_base(*str);
	while (current >= 0 && current < str_base)
	{
		nb = nb * str_base + current;
		str++;
		current = test_base(*str);
	}
	return (neg ? -nb : nb);
}

// for testing
#include <stdio.h>
#include <stdlib.h>
int		main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("num in base 10: %d\n", ft_atoi_base(av[1], atoi(av[2])));	
	}
	return (0);
}
