#include <unistd.h>

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

#include <stdio.h>
int		main(int ac, char **av)
{
	int start;
	int end;
	int len;
	int not_first_word;

	if (ac != 2 || !(av[1][0]))
	{
		write(1, "\n", 1);
		return (0);
	}
	start = 0;
	end = 0;
	len = ft_strlen(av[1]);
	not_first_word = 0;
	while (end < len)
	{
		if (is_word(av[1][end]))
		{
			start = end;
			if (not_first_word)
				write(1, " ", 1);
			while (is_word(av[1][end]))
				end++;
			print_word(av[1], start, end);
			not_first_word = 1;
		}
		end++;
	}
	write(1, "\n", 1);
	return (0);
}
