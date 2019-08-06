#include <unistd.h>

int     is_blank(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

void    rostring(char *str)
{
    int i;
    int start = 0;
    int end = 0;

    // find start and end positions of first word (if any)
    i = 0;
    while (is_blank(str[i]))
        i++;
    start = i;
    while (!is_blank(str[i]) && str[i])
        i++;
    end = i - 1;

    // print remaining string with one space between each word
    while (str[i])
    {
        while (is_blank(str[i]))
            i++;
        if (!is_blank(str[i]) && str[i])
        {
            while (!is_blank(str[i]) && str[i])
            {
                write(1, &str[i], 1);
                i++;
            }
            write(1, " ", 1);
        }
    }

    // print first word
    while (start <= end)
    {
        write(1, &str[start], 1);
        start++;
    }
}

int     main(int ac, char **av)
{
    if (ac < 2)
        return (write(1, "\n", 1));
    rostring(av[1]);
    write(1, "\n", 1);
    return (0);
}