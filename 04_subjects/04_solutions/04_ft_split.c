#include <stdlib.h>


#include <stdio.h>		// DELETE AFTER TESTING ------------


int		is_blank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

char	*word_cpy(char *str, int start, int end)
{
	char *word;
	int i = 0;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	while (start <= end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

int		word_count(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i])
	{
		while (is_blank(str[i]))
			i++;
		if (!is_blank(str[i]) && str[i])
		{
			count++;
			while (!is_blank(str[i]) && str[i])
				i++;
		}
		if (str[i] == '\0')
			break ;
	}

	return (count);
}

char	**ft_split(char *str)
{
	char **arr;
	int start, end, words;
	int i, j;

	words = word_count(str);
	arr = (char **)malloc(sizeof(char *) * words);

	i = 0;
	j = 0;
	while (str[i] && j < words)
	{
		while (is_blank(str[i]))
			i++;
		if (!is_blank(str[i]) && str[i])
		{
			start = i;
			while (!is_blank(str[i]) && str[i])
				i++;
			end = i - 1;
			arr[j] = word_cpy(str, start, end);
			j++;
		}
	}
	return (arr);
}


// for testing -- DELETE ------
#include <stdio.h>

void	print_array(char **str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%s\n", (str[i]));
		i++;
	}
}

int		main(int ac, char **av)
{
	char **arr;
	int size;

	if (ac == 2)
	{
		arr = ft_split(av[1]);
		size = word_count(av[1]);
		print_array(arr, size);
	}
	return (0);
}