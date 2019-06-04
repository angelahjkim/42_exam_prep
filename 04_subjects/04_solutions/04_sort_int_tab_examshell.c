int     greater(int a, int b)
{
    if (a == b)
        return (b);
    else if (a > b)
        return (a);
    else
        return (b);
}

int     sorted(int *tab, unsigned int size)
{
    unsigned int i;

    i = 1;
    while (i < size)
    {
        if (tab[i - 1] > tab[i])
            return (0);
        i++;
    }
    return (1);
}

void    sort_int_tab(int *tab, unsigned int size)
{
    int tmp;
    unsigned int i;

    while (!sorted(tab, size))
    {
        i = 0;
        while (i < size - 1)
        {
            if (tab[i] == greater(tab[i], tab[i + 1]))
            {
             tmp = greater(tab[i], tab[i + 1]);
              tab[i] = tab[i + 1];
               tab[i + 1] = tmp;
            }
            i++;
        }
    }
}

// for TESTING

#include <stdio.h>

void    print_array(int *arr, int size)
{
    int i = 0;

    while (i < size)
    {
        printf("%d\n", arr[i]);
        i++;
    }
}

int     main(void)
{
    int arr[] = {9, 8, 7, 6, 8, 5};
    unsigned int size = 6;

    sort_int_tab(arr, size);
    print_array(arr, size);
    return (0);
}