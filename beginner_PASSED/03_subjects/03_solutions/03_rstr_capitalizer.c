/*
** For each string, iterate through and print blanks. Once you reach the first character
** of a word, save the index as "start."
**      Get length of the word. Iterate from the start to the word length - 1, printing
**      each but the last letter 
*/

#include <stdio.h>  // DELETE AFTER TESTING

#include <unistd.h>

int     is_letter(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

int     is_word(char c)
{
    if (c == ' ' || c == '\t' || c == '\0')
        return (0);
    return (1);
}

int     is_blank(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

void    print_upper(char c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
    write(1, &c, 1);
}

void    print_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    write(1, &c, 1);
}

int     get_wordlen(char *str, int i)
{
    int len = 0;

    while (is_word(str[i]))
    {
        len++;
        i++;
    }
    return (len);
}

void    rstr_capitalizer(char *str)
{
    int i;
    int word_len;
    int start;
    //int end;         doesn't work with word ending in a non-letter "this is a word_"

    i = 0;
    while (str[i])
    {
        while (is_blank(str[i]))
        {
            write(1, &str[i], 1);
            i++;
        }
        if (is_word(str[i]))
        {
            start = 0;
            word_len = get_wordlen(str, i);
            while (start < word_len - 1)
            {
                print_lower(str[i]);
                i++;
                start++;
            }
            print_upper(str[i]);

            /*
            end = i;
            while (!(is_letter(str[end])))
                end--;
            print_upper(str[end]);
            while (end < i)
            {
                end++;
                write(1, &str[end], 1);
            }
            */

        }
        if (str[i] != '\0')
            i++;
    }
}

int     main(int ac, char **av)
{
    int i;

    if (ac == 1)
    {
        write(1, "\n", 1);
        return (0);
    }
    if (ac > 1)
    {
        i = 1;
        while (i < ac)
        {
            rstr_capitalizer(av[i]);
            write(1, "\n", 1);
            i++;
        }
    }
    return (0);
}