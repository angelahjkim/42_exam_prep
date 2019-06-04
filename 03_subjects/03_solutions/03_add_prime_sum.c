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

int     ft_atoi(char *str)
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

int     is_prime(int n)
{
    int i = 2;

    while (i < n)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int     add_prime_sum(int n)
{
    int sum = 0;
    int i = 2;

    while (i <= n)
    {
        if (is_prime(i))
            sum += i;
        i++;
    }
    return (sum);
}

int     main(int ac, char **av)
{
    int num;

    if (ac != 2)
        return (write(1, "0\n", 2));
    if (ac == 2)
    {
        num = ft_atoi(av[1]);
        ft_putnbr(add_prime_sum(num));
    }
    write(1, "\n", 1);
    return (0);
}