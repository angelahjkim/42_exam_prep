#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int num)
{
    if (num / 10)
        ft_putnbr(num / 10);
    ft_putchar(num % 10 + '0');
}

int     main(int ac, char **av)
{
    if (ac == 1)
        write(1, "0", 1);
    else
    {
        if (av[1])
            ft_putnbr(ac - 1);
    }
    write(1, "\n", 1);
    return (0);
}