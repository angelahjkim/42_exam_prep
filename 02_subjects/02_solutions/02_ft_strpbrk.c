char    *ft_strpbrk(const char *s1, const char *s2)
{
    const char  *s2_cpy;
    char        *c_ptr;

    s2_cpy = s2;

    while (*s1)
    {
        s2_cpy = s2;
        while (*s2_cpy)
        {
            if (*s1 == *s2_cpy)
            {
                c_ptr = (char *)s1;
                return (c_ptr);
            }
            s2_cpy++;
        }
        s1++;
    }
    return (0);
}

// for testing
#include <stdio.h>
#include <string.h>

int     main(int ac, char **av)
{
    char    *locate;

    if (ac == 3)
    {
        locate = ft_strpbrk(av[1], av[2]);
        printf("ft_strpbrk: %s\n", locate);

        locate = strpbrk(av[1], av[2]);
        printf("strpbrk: %s\n", locate);
    }

    return (0);
}