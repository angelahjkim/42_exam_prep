
unsigned char   reverse_bits(unsigned char octet)
{
    unsigned char r = 0;
    unsigned int byte_len = 8;

    while (byte_len)
    {
        r = (r << 1) | (octet & 1);
        octet >>= 1;
        byte_len--;
    }
    return (r);
}

/*
unsigned char   reverse_bits(unsigned char octet)
{
    octet = (octet & 0xF0) >> 4 | (octet & 0x0F) << 4;
    octet = (octet & 0xCC) >> 2 | (octet & 0x33) << 2;
    octet = (octet & 0xAA) >> 1 | (octet & 0x55) << 1;
    return (octet);
}
*/

// -------------------------------------- for testing only

#include <unistd.h>
void    print_bits(unsigned char octet)
{
    int i = 256;

    while (i >>= 1)
    {
        if (octet & i)
            write(1, "1", 1);
        else
            write(1, "0", 1);
    }
}

int     main(void)
{
    unsigned char c = 'b';

    print_bits(c);
    write(1, "\n", 1);

    c = reverse_bits(c);
    print_bits(c);
    write(1, "\n", 1);

    return (0);
}