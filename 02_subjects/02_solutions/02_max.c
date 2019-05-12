int     max(int *tab, unsigned int len)
{
    unsigned int i = 0;
    int max = 0;

    if (len == 0)
        return (0);
    if (len > 0)
        max = tab[i];
    while (i < len)
    {
        if (tab[i] > max)
            max = tab[i];
        i++;
    }
    return (max);
}

// delete after testing
#include <stdio.h>
int     main(void)
{
    int tab[] = {3, 0, 42, -1, 100};
    int size = 5;

    printf("%d\n", max(tab, size));

    return (0);
}