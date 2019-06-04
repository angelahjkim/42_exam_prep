#include <unistd.h>

// if there are no words, display newline

/*
** test cases:
** "" 
** "         "
** "one"
** " space "
** "    spaces before   and after   "
** " = "
*/

#include <stdio.h>  // testing

int     is_blank(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

void    expand_str(char *str)
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
                i++;
            }
        }
        while (is_blank(str[i]))
            str++;
        if (str[i] != '\0')
            write(1, "   ", 3);
    }
}

int     main(int ac, char **av)
{
    if (ac == 2)
    {
        expand_str(av[1]);
    }
    write(1, "\n", 1);
    return (0);
}