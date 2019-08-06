#include <unistd.h>

int		isBlank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	strCapitalize(char *str)
{
	int i = 0;
	while (str[i])
	{
		while (isBlank(str[i]))
		{
			write(1, &str[i], 1);
			i++;
		}
		if (!isBlank(str[i]) && str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			write(1, &str[i], 1);
			i++;
			while (!isBlank(str[i]) && str[i])
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					str[i] += 32;
				write(1, &str[i], 1);
				i++;
			}
		}
	}
}

int		main(int ac, char **av)
{
	int i;

	if (ac < 2)
		return (write(1, "\n", 1));
	i = 1;
	while (i < ac)
	{
		strCapitalize(av[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}