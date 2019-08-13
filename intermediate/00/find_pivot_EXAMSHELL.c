int     find_pivot(int *arr, int n)
{
    int sum_down;
    int sum_up;
    int i;

    i = 0;
    sum_down = 0;
    while(i < n)
    {
        sum_down += arr[i];
        i++;
    }
    i = n - 1;
    sum_up = 0;
    while (i > 0)
    {
        if (sum_down - arr[i] == sum_up)
            return (i);
        sum_up += arr[i];
        sum_down -= arr[i];
        i--;
    }
    return (-1);
}

// for testing
#include <stdio.h>

int     main(void)
{
    int arr[] = {1, 2};
    int size = 2;

    printf("pivot: %d\n", find_pivot(arr, size));

    return (0);
}