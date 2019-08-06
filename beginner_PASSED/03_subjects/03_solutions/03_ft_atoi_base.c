/*
** FT_ATOI_BASE: Write a function that converts the string argument str (base N <= 16)
** to an integer (base 10) and returns it. Uppercase letters must also be recognized.
** Minus signs '-' are interpreted only if they are the first character of the string.
*/

int		base_conv(const char c)
{
	int num;

	if (c >= '0' && c <= '9')
		num = c - '0';
	else if (c >= 'a' && c <= 'f')
		num = c - 'a' + 10;
	else if (c >= 'A' && c <= 'F')
		num = c - 'A' + 10;
	else
		num = -1;
	return (num);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int num;
	int current;
	int neg;

	num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f' ||
			*str == '\r' || *str == '\v')
		str++;
	neg = (*str == '-' ? 1 : 0);
	if (*str == '-' || *str == '+')
		str++;
	current = base_conv(*str);
	while (current >= 0 && current < str_base)
	{
		num = num * str_base + current;
		str++;
		current = base_conv(*str);
	}
	return (neg ? -num : num);
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
