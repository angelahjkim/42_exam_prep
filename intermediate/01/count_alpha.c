#include <stdio.h>

typedef struct	s_alpha
{
	char		letter;
	int			occ;
}				t_alpha;


void	count_alpha(char *str)
{
	t_alpha	tracker[26];
	int		i = 0;
	int		count = 0;
	int		j;
	char	c;

	while (i < 26)
	{
		tracker[i].letter = ' ';
		tracker[i].occ = 0;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			j = 0;
			if (str[i] >= 'a' && str[i] <= 'z')
				c = str[i] - 'a';
			else
				c = str[i] - 'A';
			while (j < count)
			{
				if (tracker[j].letter == c)
					break ;
				j++;
			}
			if (j == count)
			{
				tracker[j].letter = c;
				count++;
			}
			tracker[j].occ++;
		}
		i++;
	}
	i = 0;
	while (i < count)
	{
		printf("%d%c%s", tracker[i].occ, tracker[i].letter + 'a', i == count - 1 ? "" : ", ");
		i++;
	}
}

int     main(int ac, char **av)
{
    if (ac == 2)
		count_alpha(av[1]);
    printf("\n");
    return (0);
}