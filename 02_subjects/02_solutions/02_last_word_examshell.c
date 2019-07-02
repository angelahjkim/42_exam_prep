#include <unistd.h>

int		is_blank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	print_lastword(char *str)
{
	int start = 0;
	int	end = 0;
	int i = 0;

	while (str[i])
	{
		while (is_blank(str[i]))
			i++;
		if (!is_blank(str[i]) && str[i])
		{
			start = i;
			while (!is_blank(str[i]))
			{
				i++;
				if (str[i] == '\0')
				{
					end = i - 1;
					break ;
				}
			}
			end = i - 1;
		}
	}

	while (start <= end && end != 0)
	{
		write(1, &str[start], 1);
		start++;
	}
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1));

	print_lastword(av[1]);
	write(1, "\n", 1);
	return (0);
}