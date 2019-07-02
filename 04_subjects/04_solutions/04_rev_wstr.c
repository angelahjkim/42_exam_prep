#include <stdlib.h>
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

int     ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return (len);
}

char    *rev_wstr(char *str)
{
    char *new_str;
    int i, len, start, end;

    len = ft_strlen(str);
    new_str = (char *)malloc(sizeof(char) * len);
    new_str[len] = '\0';

    // reverse order of words in new_str

    return (new_str);
}

int     main(int ac, char **av)
{
    char *result = NULL;

    if (ac == 2)
    {
        result = rev_wstr(av[1]);
        ft_putstr(result);
        free(result);
    }
    write(1, "\n", 1);
    return (0);
}