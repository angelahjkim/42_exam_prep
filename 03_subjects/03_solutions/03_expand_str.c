#include <unistd.h>

int		is_word(char c)
{
	if (c == ' ' || c == '\t' || c == '\0')
		return (0);
	return (1);
}

void	print_word(char *str, int start, int end)
{
	while (start < end)
	{
		write(1, &str[start], 1);
		start++;
	}
}

int		ft_strlen(char *str)
{
	int len = 0;
	
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int		main(int ac, char **av)
{
	int len;
	int start;
	int end;
	int	not_first;

	if (ac == 2)
	{
		len = ft_strlen(av[1]);
		start = 0;
		end = 0;
		not_first = 0;
		while (end < len)
		{
			if (is_word(av[1][end]))
			{
				if (not_first)
					write(1, "   ", 3);
				start = end;
				while (is_word(av[1][end]))
					end++;
				print_word(av[1], start, end);
				not_first = 1;
			}
			end++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
