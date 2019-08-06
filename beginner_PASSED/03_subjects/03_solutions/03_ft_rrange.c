#include <stdlib.h>

int		*ft_rrange(int start, int end)
{
	int	*rrange;
	int i;

	if (start > end)
		rrange = (int *)malloc(sizeof(int) * (start - end) + 1);
	else
		rrange = (int *)malloc(sizeof(int) * (end - start) + 1);
	i = 0;
	while (start != end)
	{
		rrange[i++] = end;
		end -= (start > end) ? -1 : 1;
	}
	rrange[i] = end;
	return (rrange);
}

// for testing
#include <stdio.h>
#include <stdlib.h>

int		get_size(int start, int end)
{
	int size;

	if (start > end)
		size = start - end + 1;
	else
		size = end - start + 1;
	return (size);
}

void	print_array(int *array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%d\n", array[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	int start;
	int end;
	int *array;
	int size;

	if (ac == 3)
	{
		start = atoi(av[1]);
		end = atoi(av[2]);
		size = get_size(start, end);
		array = ft_rrange(start, end);
		print_array(array, size);
	}
	return (0);
}
