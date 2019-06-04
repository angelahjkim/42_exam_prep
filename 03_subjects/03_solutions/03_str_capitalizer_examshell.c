#include <unistd.h>

int		is_blank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		is_letter(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

void	make_upper(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
		write(1, &c, 1);
	}
	else
		write(1, &c, 1);
}

void	make_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
		write(1, &c, 1);
	}
	else
		write(1, &c, 1);
}

void	str_capitalizer(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (is_blank(str[i]) && str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		if (!is_blank(str[i]))
		{
			while (!is_letter(str[i]) && str[i])
			{
				write(1, &str[i], 1);
				i++;
			}
			if (is_letter(str[i]) && (i == 0 || is_blank(str[i - 1])))
			{
				make_upper(str[i]);
				i++;
			}
			while (is_letter(str[i]) && str[i])
			{
				make_lower(str[i]);
				i++;
			}
		}
		if (str[i])
			write(1, &str[i], 1);
		if (str[i] == '\0')
			break ;
		i++;
	}
	write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	int i;

	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		str_capitalizer(av[i]);
		i++;
	}
	return (0);
}