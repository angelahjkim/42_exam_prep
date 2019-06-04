#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int *range;
    int size;
    int i;

    if (start == 0 && end == 0)
    {
        size = 1;
        range = (int *)malloc(sizeof(int) * size);
        range[0] = 0;
        return (range);
    }
    else if (start < end)
    {
        size = end - start + 1;
        range = (int *)malloc(sizeof(int) * size);
        i = 0;
        while (i < size)
        {
            range[i] = start;
            start++;
            i++;
        }
        return (range);
    }
    else if (start > end)
    {
        size = start - end + 1;
        range = (int *)malloc(sizeof(int) * size);
        i = 0;
        while (i < size)
        {
            range[i] = start;
            start--;
            i++;
        }
        return (range);
    }
    else
        range = NULL;
    return (range);
}

// for testing

#include <stdio.h>

void    print_array(int *array, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf("%d\n", array[i]);
        i++;
    }
}

int     main(int ac, char **av)
{
    int start = atoi(av[1]);
    int end = atoi(av[2]);
    int size = atoi(av[3]);

    if (ac == 4)
    {
        print_array(ft_range(start, end), size);
    }
    return (0);
}