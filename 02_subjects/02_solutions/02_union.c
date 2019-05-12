#include <unistd.h>

int     is_unique(char *str, int pos)
{
    int i = 0;

    while (i < pos)
    {
        if (str[i] == str[pos])
            return (0);
        i++;
    }
    return (1);
}

int     main(int argc, char **argv)
{
    int i;
    int j;

    if (argc == 3)
    {
        
    }
    write(1, "\n", 1);
    return (0);
}