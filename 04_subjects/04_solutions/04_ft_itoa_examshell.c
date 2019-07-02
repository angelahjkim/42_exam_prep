#include <stdlib.h>

int     digit_count(int nbr)
{
    int count = 0;

    if (nbr == 0)
        return (1);
    if (nbr < 0)
        count++;
    while (nbr)
    {
        nbr /= 10;
        count++;
    }
    return (count);
}

char    *ft_itoa(int nbr)
{
    char    *num_str;
    int     size;
    int     neg = 1;

    size = digit_count(nbr);
    num_str = (char *)malloc(sizeof(char) * (size + 1));

    num_str[size] = '\0';
    
    if (nbr == 0)
    {
        num_str[0] = '0';
        return (num_str);
    }
    if (nbr < 0)
    {
        num_str[0] = '-';
        neg = -1;
    }
    while (nbr)
    {
        num_str[size - 1] = neg * (nbr % 10) + '0';
        nbr /= 10;
        size--;
    }

    return (num_str);
}

// for testing ONLY
#include <stdio.h>
#include <limits.h>

int     main(void)
{
    int num = INT_MIN;

    printf("%s\n", ft_itoa(num));
    return (0);
}