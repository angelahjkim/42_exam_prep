int     is_power_of_2(unsigned int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    while (n > 1)
    {
        if (n % 2 == 1)
            return (0);
        n /= 2;
    }
    return (1);
}

// for testing ONLY
#include <stdio.h>
#include <stdlib.h>

int     main(int ac, char **av)
{
    if (ac == 2)
    {
        printf("is power of 2 [1 or 0]: %d\n", is_power_of_2(atoi(av[1])));
    }

    return (0);
}