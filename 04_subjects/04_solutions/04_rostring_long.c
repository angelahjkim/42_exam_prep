// test cases:	"one"
//				"   one"
//				"  one  "

#include <unistd.h>
#include <stdlib.h>

int		is_blank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	printStr(char *str)
{
	int i = 0;

	while (is_blank(str[i]))
		i++;
	while (!is_blank(str[i]) && str[i])
		i++;
	while (str[i])
	{
		while (is_blank(str[i]))
			i++;
		while (!is_blank(str[i]) && str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		if (str[i])
			write(1, " ", 1);
	}
}

char	*getFirstWord(char *str)
{
	int i = 0;
	int start = 0, end = 0;
	char *firstWord;

	while (str[i])
	{
		while (is_blank(str[i]))
			i++;
		if (!is_blank(str[i]) && str[i])
		{
			start = i;
			while (!is_blank(str[i]) && str[i])
				i++;
			end = i - 1;
		}
		break ;
	}
	firstWord = (char *)malloc(sizeof(char) * (end - start + 1));
	i = 0;
	while (start <= end)
	{
		firstWord[i] = str[start];
		i++;
		start++;
	}
	firstWord[i] = '\0';
	return (firstWord);
}

int		oneWord(char *str)
{
	int i = 0;

	while (str[i])
	{
		while (!is_blank(str[i]))
			i++;
		if (is_blank(str[i]))
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>	// for testing -- DELETE --
int		main(int ac, char **av)
{
	char *firstWord;

	if (ac > 1)
	{
		firstWord = getFirstWord(av[1]);
		if (!oneWord(av[1]))
		{
			puts("HERE");
			printStr(av[1]);
			write(1, " ", 1);
		}
		ft_putstr(firstWord);
	}
	write(1, "\n", 1);
	return (0);
}
