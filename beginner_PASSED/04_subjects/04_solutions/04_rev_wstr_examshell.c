#include <unistd.h>

void	ft_putword(char *str, int start, int end)
{
	while (start <= end)
	{
		write(1, &str[start], 1);
		start++;
	}
}

int		is_blank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}

void	rev_wstr(char *str)
{
	int i = ft_strlen(str) - 1;
	int start;
	int end;


	while (str[i] && i > 0)
	{
		while (is_blank(str[i]))
			i--;
		end = i;
		while (!is_blank(str[i]) && i > 0)
			i--;
		if (i == 0)
			start = 0;
		else
			start = i + 1;
		ft_putword(str, start, end);
		while (is_blank(str[i]))
			i--;
		if (i > 0)
			write(1, " ", 1);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		rev_wstr(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}