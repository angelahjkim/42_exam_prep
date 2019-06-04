#include <unistd.h>

void	ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	int i;
	int j;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	j = 0;
	while (av[1][i])
	{
		while (av[2][j])
		{
			if (av[1][i] == av[2][j])
				i++;
			j++;
		}
		if (av[2][j] == '\0')
			break ;
	}
	if (av[1][i] == '\0')
		ft_putstr(av[1]);
	write(1, "\n", 1);
	return (0);
}