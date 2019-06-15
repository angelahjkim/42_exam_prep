#include <stdio.h>
#include <stdlib.h>

void	print_gcd(int a, int b)
{
	int lower;
	int gcd;

	gcd = 1;
	lower = a;
	if (a > b)
		lower = b;
	while (lower > 1)
	{
		if (a % lower == 0 && b % lower == 0)
		{
			gcd = lower;
			break ;
		}
		lower--;
	}
	printf("%d", gcd);
}

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		print_gcd(atoi(av[1]), atoi(av[2]));
	}
	printf("\n");
	return (0);
}