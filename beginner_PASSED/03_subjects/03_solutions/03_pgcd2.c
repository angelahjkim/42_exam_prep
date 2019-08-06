#include <stdio.h>
#include <stdlib.h>

int     get_gcd(int a, int b)
{
    int lower = a;
    int gcd = 1;
    int i = 1;

    if (a > b)
        lower = b;
    while (i <= lower)
    {
        if (a % i == 0 && b % i == 0)
            gcd = i;
        i++;
    }
    return (gcd);
}

int     main(int ac, char **av)
{
    if (ac == 3)
    {
        printf("%d", get_gcd(atoi(av[1]), atoi(av[2])));
    }
    printf("\n");
    return (0);
}