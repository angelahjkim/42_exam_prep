#include <unistd.h>

int		ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

int		main(int ac, char **av)
{
	int i;
	int end;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	end = ft_strlen(av[1]);
	while (--end)
		write(1, &av[1][end], 1);
	write(1, &av[1][end], 1);
	write(1, "\n", 1);
	return (0);
}