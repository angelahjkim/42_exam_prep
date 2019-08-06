#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &str, 1);
		str++;
	}
}

void	to_upper(char *str, int pos)
{
	*(str + pos) = str[pos];
}

int		is_word(char c)
{
	if (c == ' ' || c == '\t' || c == '\0')
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	int i;

	if (ac == 1)
	{
		i = 0;
		while (av[1][i])
		{
			if (is_word(av[1][i]))
			{
				while (is_word(av[1][i]))
					i++;
				i--;
				to_upper(av[1], i);
			}
			i++;
		}
		ft_putstr(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
