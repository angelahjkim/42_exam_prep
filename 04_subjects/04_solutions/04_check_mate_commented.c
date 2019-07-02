#include <unistd.h>

int     check_ortho(char **board, int k_row, int k_col, int r_max, int c_max)
{
    // initialize r and c to the row and column positions of the King
    int r = k_row;
    int c = k_col;

    // check for pieces that can check the King from upwards: Q, R
    while (--r >= 0)
    {
        if (board[r][c] == 'Q' || board[r][c] == 'R')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] == 'B')
            break ;
    }

    // reinitialize to King's position and check downwards for pieces that can check: Q, R
    r = k_row;
    c = k_col;
    while (++r <= r_max)
    {
        if (board[r][c] == 'Q' || board[r][c] == 'R')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] == 'B')
            break ;
    }

    // reinitialize and check for pieces that can check from left: Q, R
    r = k_row;
    c = k_col;
    while (--c >= 0)
    {
        if (board[r][c] == 'Q' || board[r][c] == 'R')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] == 'B')
            break ;
    }

    // reinitialize and check for pieces that can check from right: Q, R
    r = k_row;
    c = k_col;
    while (++c <= c_max)
    {
        if (board[r][c] == 'Q' || board[r][c] == 'R')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] == 'B')
            break ;
    }

    // if no checks possible
    return (0);
}

int     check_diag(char **board, int k_row, int k_col, int r_max, int c_max)
{
    int r = k_row;
    int c = k_col;

    // check for pieces that can check diagonally from down-leftwards: Q, B, & P
    while (++r <= r_max && --c >= 0)
    {
        if (r == k_row + 1 && c == k_col - 1 && board[r][c] == 'P')
            return (1);
        else if (board[r][c] == 'Q' || board[r][c] == 'B')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] =='R')
            break ;
    }

    // check for pieces that can check diagonally from down-rightwards: Q, B, & P
    r = k_row;
    c = k_col;
    while (++r <= r_max && ++c <= c_max)
    {
        if (r == k_row + 1 && c == k_col + 1 && board[r][c] == 'P')
            return (1);
        else if (board[r][c] == 'Q' || board[r][c] == 'B')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] == 'R')
            break ;
    }

    // check for pieces that can check diagonally from up-leftwards: Q, B
    r = k_row;
    c = k_col;
    while (--r >= 0 && --c >= 0)
    {
        if (board[r][c] == 'Q' || board[r][c] == 'B')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] == 'R')
            break ;
    }

    // check for pieces that can check diagonally from up-rightwards: Q, B
    r = k_row;
    c = k_col;
    while (--r >= 0 && ++c <= c_max)
    {
        if (board[r][c] == 'Q' || board[r][c] == 'B')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] == 'R')
            break ;
    }

    // if no checks
    return (0);
}

int     get_kcol(char *row)
{
    int c = 0;

    while (row[c])
    {
        if (row[c] == 'K')
            return (c);
        c++;
    }
    return (-1);
}

int     get_krow(char **board, int r_max)
{
    int r, c;

    r = 0;
    while (r <= r_max)
    {
        c = 0;
        while (board[r][c])
        {
            if (board[r][c] == 'K')
                return (r);
            c++;
        }
        r++;
    }
    return (-1);
}

int     main(int ac, char **av)
{
    // set up variable for board
    char **board = &av[1];

    int k_row, k_col, row_max, col_max;

    if (ac < 2)
        return (write(1, "\n", 1));

    row_max = ac - 2;
    col_max = row_max;

    k_row = get_krow(board, row_max);
    k_col = get_kcol(board[k_row]);

    if (check_ortho(board, k_row, k_col, row_max, col_max) == 1)
        return (write(1, "Success\n", 8));
    else if (check_diag(board, k_row, k_col, row_max, col_max) == 1)
        return (write(1, "Success\n", 8));
    else
        return (write(1, "Fail\n", 5));

    return (0);
}