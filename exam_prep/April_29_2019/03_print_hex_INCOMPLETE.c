#include <unistd.h>

#include <stdio.h>

int     main(int argc, char **argv)
{
    if (argc == 2)
    {
        char hex_digits[] = "0123456789abcdef";
        unsigned int num = 0;
        int i = 0;
        
        while (argv[1][i])
        {
            num = (num * 10) + (argv[1][i] - '0') % 10;
            i++;
        }
printf("num base_10: %d\n", num);
        if (num == 0)
            write(1, "0", 1);
        while (num)
        {
            write(1, &hex_digits[num % 16], 1);
            num /= 16;
        }
    }
    write(1, "\n", 1);
    return (0);
}