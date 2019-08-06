#include <unistd.h>

int		is_blank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int i;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (av[1][i])
	{
		while (is_blank(av[1][i]))
		{
			i++;
			if (av[1][i] == '\0')
			{
				write(1, "\n", 1);
				return (0);
			}
		}
		while (!is_blank(av[1][i]))
		{
			write(1, &av[1][i], 1);
			i++;
			if (av[1][i] == '\0')
			{
				write(1, "\n", 1);
				return (0);
			}
		}
		if (is_blank(av[1][i]))
		{
			write(1, "\n", 1);
			return (0);
		}
		i++;
	}
	return (0);
}