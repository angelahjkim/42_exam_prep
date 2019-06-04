#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int n)
{
    if (n / 10)
        ft_putnbr(n / 10);
    ft_putchar(n % 10 + '0');
}

void    ft_putstr(char *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
}

int    ft_atoi(char *str)
{
    int num = 0;

    if (*str == '+')
        str++;
    while (*str)
    {
        num = num * 10 + (*str - '0');
        str++;
    }
    return (num);
}

void     print_table(int n)
{
    int i = 1;
    int result;

    while (i < 10)
    {
        result = n * i;
        ft_putnbr(i);
        ft_putstr(" x 9 = ");
        ft_putnbr(result);
        if (i != 9)
            ft_putchar('\n');
        i++;
    }
}

int     main(int ac, char **av)
{
    if (ac > 1)
    {
        print_table(ft_atoi(av[1]));
    }
    write(1, "\n", 1);
    return (0);
}