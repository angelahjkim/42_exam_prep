#include <unistd.h>

int		is_blank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	epur_str(char *str)
{
	int i = 0;

	while (str[i])
	{
		while (is_blank(str[i]))
			i++;
		while (!is_blank(str[i]) && str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		while (is_blank(str[i]))
			i++;
		if (str[i] != '\0')
			write(1, " ", 1);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		epur_str(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}