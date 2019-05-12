#include <unistd.h>

int     is_unique(char *str, int pos)
{
    int i;

    i = 0;
    while (i < pos)
    {
        if (str[i] == str[pos])
            return (0);
        i++;
    }
    return (1);
}

int     main(int ac, char **av)
{
    int i;
    int j;

    if (ac == 3)
    {
        i = 0;
        while (av[1][i])
        {
            j = 0;
            while (av[2][j])
            {
                if (av[2][j] == av[1][i] && is_unique(av[1], i))
                    write(1, &av[1][i], 1);
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}