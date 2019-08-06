#include <unistd.h>

/*
** test cases:
**      ""
**      " "
**      "one"
**      " space "
**      "   spaces before    and   .    after    "
*/

int     is_blank(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

void    space_str(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        while (is_blank(str[i]))
            str++;
        if (!is_blank(str[i]))
        {
            while (!is_blank(str[i]) && str[i] != '\0')
            {
                write(1, &str[i], 1);
                str++;
            }
        }
        while (is_blank(str[i]))
            str++;
        if (str[i] != '\0')
            write(1, " ", 1);
    }
}

int     main(int ac, char **av)
{
    if (ac == 2)
    {
        space_str(av[1]);
    }
    write(1, "\n", 1);
    return (0);
}