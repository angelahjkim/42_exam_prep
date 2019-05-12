unsigned char   swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));
}


//  Testing
#include <unistd.h>

void    print_bits(unsigned char octet)
{
    int i = 256;

    while (i)
    {
        if (octet & i)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        i /= 2;
    }
}

int     main(void)
{
    unsigned char c = '&';

    print_bits(c);
    write(1, "\n", 1);
    c = swap_bits(c);
    print_bits(c);
    write(1, "\n", 1);

    return (0);
}