#include <unistd.h>

int		main(int ac, char **av)
{
	int i = 0;
	int j = 0;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	// if the first argument is an empty string
	if (av[1][0] == '\0')
	{
		write(1, "1\n", 2);
		return (0);
	}
	// look for first character in the first argument in the second, if found go to next
	// if end of string reached, it is "hiden"
	while (av[2][i] != '\0')
	{
		if (av[1][j] == '\0')
		{
			write(1, "1\n", 2);
			return (0);
		}
		if (av[1][j] == av[2][i])
			j++;
		i++;
	}
	// if both argument strings are the same, it is "hiden"
	if (av[1][i] == '\0')
	{
		write(1, "1\n", 2);
		return (0);
	}
	write(1, "0\n", 2);
	return (0);
}
