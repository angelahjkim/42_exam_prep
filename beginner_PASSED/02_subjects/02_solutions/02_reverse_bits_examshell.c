unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char rev;
	int	byte_size = 8;

	while (byte_size--)
	{
		rev = (rev << 1) | (octet & 1);
		octet >>= 1;
	}
	return (rev);
}

// for testing ONLY --------
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