// Test Case: ".Rmjok7,CDm6quocAl8ZzF9" "e" "K" | cat -e
// Return : .Rmjok7,CDm6quocAl8ZzF9$

#include <unistd.h>

void    ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int    is_found(char *str, char old, char new)
{
    int i = 0;
    int f_found = 0;

    while (str[i])
    {
        if (str[i] == old)
        {
            f_found = 1;
            str[i] = new;
        }
        i++;
    }
    if (f_found)
    {
        ft_putstr(str);
        return (1);
    }
    return (0);
}

int     main(int ac, char **av)
{
    if (ac != 4 || av[2][1] != '\0' || av[3][1] != '\0')
        return (write(1, "\n", 1));
    if (!is_found(av[1], av[2][0], av[3][0]))
        ft_putstr(av[1]);
    write(1, "\n", 1);
    return (0);
}