#include <unistd.h>

#include <stdio.h>

/*
** Check if valid string (has at least one word). Find string length
** and reading from the end of the string, find and print the last word
** "word "
*/

int		ft_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int		is_blank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int word_start;
	int end;

	if (ac == 2)
	{
		end = ft_strlen(av[1]);
		while (end)
		{
			while (is_blank(av[1][end]))
				end--;
			word_start = end;
printf("word_start: %d\n", word_start);
			while (!(is_blank(av[1][end])))
			{
				word_start--;
				end--;
			}
printf("\tword_start: %d\n", word_start);
		}
		while (!(is_blank(av[1][word_start])))
		{
			write(1, &av[1][word_start], 1);
			word_start++;
printf("\t\tword_start: %d\n", word_start);
		}
	}
	write(1, "\n", 1);
}
