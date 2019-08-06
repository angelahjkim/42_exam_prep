#include <stdio.h>

void    print_doublon(int *a, int na, int *b, int nb)
{
    int ia = 0;
    int ib = 0;
    int pvs = 0;

    while (ia < na && ib < nb)
    {
        if (a[ia] == b[ib])
        {
            printf("%s%d", pvs == 1 ? " " : "", a[ia]);
            pvs = 1;
        }
        if (a[ia] > b[ib])
            ib++;
        else
            ia++;
    }
    printf("\n");
}

// for testing
int     main(void)
{
    int a[] = {-5, 0, 3, 42, 100};
    int na = 5;
    int b[] = {3, 42};
    int nb = 2;

    print_doublon(a, na, b, nb);

    return (0);
}