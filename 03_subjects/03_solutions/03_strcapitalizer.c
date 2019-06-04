#include <unistd.h>

int     is_blank(char c)
{
    if (c == ' ' || c == '\t' || c == '\0')
        return (1);
    return (0);
}

int     is_letter(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

void    make_upper(char c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
    write(1, &c, 1);
}

void    make_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    write(1, &c, 1);
}

void    str_capitalizer(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        while (is_blank(str[i]))
        {
            write(1, &str[i], 1);
            i++;
        }
        if (!(is_blank(str[i])) && str[i] != '\0')
        {
            while (!(is_letter(str[i])))
            {
                write(1, &str[i], 1);
                i++;
            }
            make_upper(str[i]);
            i++;
            while (!(is_blank(str[i])))
            {
               make_lower(str[i]);
               i++;
            }
            i--;
        }
        if (str[i] != '\0')
            i++;
    }
}

int     main(int ac, char **av)
{
    int i;

    if (ac == 1)
    {
        write(1, "\n", 1);
        return (0);
    }
    else
    {
        i = 1;
        while (i < ac)
        {
            str_capitalizer(av[i]);
            write(1, "\n", 1);
            i++;
        }
    }
    return (0);
}