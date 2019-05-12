/*
** PGCD: Write a program that takes two strings representing two strictly
** positive integers that fit in an int. Display their highest common
** denominator followed by a newline.
*/

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	int n1;
	int n2;
	int lower;
	int i;
	int gcd = 0;

	if (ac == 3)
	{
		n1 = atoi(av[1]);
		n2 = atoi(av[2]);
		lower = n1;
		if (n2 < n1)
			lower = n2;
		i = 1;
		while (i <= lower)
		{
			if (n1 % i == 0 && n2 % i == 0)
				gcd = i;
			i++;
		}
		printf("%d", gcd);
	}
	printf("\n");
	return (0);
}
