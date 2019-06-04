#include <unistd.h>

int		is_new(char *str, int pos)
{
	int i = 0;

	while (i < pos)
	{
		if (str[i] == str[pos])
			return (0);
		i++;
	}
	return (1);
}

void	inter(char *one, char *two)
{
	int i;
	int j;

	i = 0;
	while (one[i])
	{
		j = 0;
		while (two[j])
		{
			if (one[i] == two[j] && is_new(one, i) && is_new(two, j))
				write(1, &one[i], 1);
			j++;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		inter(av[1], av[2]);
	}
	write(1, "\n", 1);
	return (0);
}