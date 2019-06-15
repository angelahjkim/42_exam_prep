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

int		ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}

void	rev_str(char *str)
{
	char tmp;
	int i, len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		tmp = str[len - 1];
		str[len - 1] = str[i];
		str[i] = tmp;
		i++;
		len--;
	}
	ft_putstr(str);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		rev_str(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}