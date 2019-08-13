#include <stdio.h>

/*
    A B         (10 * A) + B    -->     n
    C A         (10 * C) + A    -->
    ---
    * #         * == (n / 10); % == (n % 10)


    10 * A + B + 10 * C + A == n
*/

void    equation(int n)
{
    int a, b, c;

    a = 0;
    while (a < 10)
    {
        b = 0;
        while (b < 10)
        {
            c = 0;
            while (c < 10)
            {
                if (10 * a + b + 10 * c + a == n)
                    printf("A = %d, B = %d, C = %d\n", a, b, c);
                c++;
            }
            b++;
        }
        a++;
    }
}

// for testing (mouilinette uses their own main)
#include <stdlib.h>
int     main(int ac, char **av)
{
    if (ac == 2)
    {
        equation(atoi(av[1]));
    }
    return (0);
}