#include <unistd.h>

int     is_letter(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

void    print_upper(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        c -= 32;
        write(1, &c, 1);
    }
    else
        write(1, &c, 1);
}

void    rstr_capitalizer(char *str)
{
    while (*str)
    {
        while (!is_letter(*str) && *str)
        {
            write(1, str, 1);
            str++;
        }
        if (is_letter(*str))
        {
            while (is_letter(*str) && *str)
            {
                if (!is_letter(*(str + 1)) || *(str + 1) == '\0')
                    print_upper(*str);
                else if (*str >= 'A' && *str <= 'Z')
                {
                    *str += 32;
                    write(1, str, 1);
                }
                else
                    write(1, str, 1);
                str++;
            }
        }
    }
}

int     main(int ac, char **av)
{
    int i;

    if (ac > 1)
    {
        i = 1;
        while (i < ac)
        {
            rstr_capitalizer(av[i]);
            if (i < ac - 1)
                write(1, "\n", 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}