#include <unistd.h>

int		ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}

int		is_unique(char *str, int pos, char c)
{
	int i = 0;

	while (i < pos)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	print_union(char *s1, char *s2)
{
	int i, s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	while (s1[i])
	{
		if (is_unique(s1, i, s1[i]))
			write(1, &s1[i], 1);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (is_unique(s1, s1_len, s2[i]) && is_unique(s2, i, s2[i]))
			write(1, &s2[i], 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac != 3)
		return (write(1, "\n", 1));

	print_union(av[1], av[2]);
	write(1, "\n", 1);

	return (0);
}