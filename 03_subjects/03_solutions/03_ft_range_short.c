#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int *range;
	int i;

	if (start > end)
		range = (int *)malloc(sizeof(int) * (start - end) + 1);
	else
		range = (int *)malloc(sizeof(int) * (end - start) + 1);
	i = 0;
	while (start != end)
	{
		range[i++] = start;
		start += (start > end) ? -1 : 1;
	}
	range[i] = start;
	return (range);
}

// for testing
#include <stdio.h>
void	print_array(int *array, int size)
{
	int i = 0;

	while (i < size)
	{
		printf("%d\n", array[i]);
		i++;
	}
}

int		get_size(start, end)
{
	int size = 0;
	
	if (start > end)
		size = start - end + 1;
	else
		size = end - start + 1;
	return (size);
}

int		main(int ac, char **av)
{
	int *array;
	int size;
	int start;
	int end;

	if (ac == 3)
	{
		start = atoi(av[1]);
		end = atoi(av[2]);
		size = get_size(start, end);
		array = ft_range(start, end);
		print_array(array, size);
	}
	return (0);
}
