#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	char *src_cpy;
	int	len;
	int i;

	len = 0;
	while (src[len])
		len++;
	src_cpy = (char *)malloc(sizeof(char) * len + 1);
	if (src_cpy)
	{
		i = 0;
		while (len)
		{
			src_cpy[i] = src[i];
			len--;
			i++;
		}
		src_cpy[i] = '\0';
		return (src_cpy);
	}
	return (NULL);
}




int		main(int ac, char **av)
{
	char *str_cpy = NULL;

	if (ac == 2)
	{
		printf("str_cpy: %s\n", str_cpy);
		str_cpy = ft_strdup(av[1]);
		printf("str_cpy after ft_strdup: %s\n", str_cpy);
		free(str_cpy);
	}
	return (0);
}
