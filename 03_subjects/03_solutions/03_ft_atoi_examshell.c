// test cases:	"42"
// 				"-42"
// 				"     -42abc"
// 				"0"
// 				"abc42"

int		ft_atoi(const char *str)
{
	int i = 0;
	int neg = 1;
	int num = 0;

	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f' ||
				str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				neg = -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			num = (num * 10) + (str[i] - '0');
			i++;
		}
		break ;
	}
	return (num * neg);
}

// for testing -- DELETE --
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("INT_MIN: %d\n", INT_MIN);
		printf("ft_atoi: %d\n", ft_atoi(av[1]));
		printf("atoi: %d\n", atoi(av[1]));
	}
	return (0);
}