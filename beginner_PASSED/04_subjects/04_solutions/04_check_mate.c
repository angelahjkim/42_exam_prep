#include <unistd.h>

#include <stdio.h>      // for testing -- DELETE ---------

int     check_diag(char **board, int r_max, int c_max, int k_row, int k_col)
{
    int r = k_row;
    int c = k_col;

    // check for pieces that can capture from diagonally up-rightward: Q, B.
    while (--r >= 0 && ++c <= c_max)
    {
        if (board[r][c] == 'Q' || board[r][c] == 'B')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] == 'R')
            break ;
    }

    // check for pieces that can capture from diagonally up-leftward: Q, B.
    r = k_row;
    c = k_col;
    while (--r >= 0 && --c >= 0)
    {
        if (board[r][c] == 'B' || board[r][c] == 'Q')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] == 'R')
            break ;
    }

    // check for pieces that can capture from diagonally down-rightward: Q, B, & P.
    r = k_row;
    c = k_col;
    while (++r <= r_max && ++c <= c_max)
    {
        if (c == k_col + 1 && r == k_row + 1 && board[r][c] == 'P')
        {
puts("\tPawn checkmate! From down-right.");
            return (1);
        }
        else if (board[r][c] == 'Q' || board[r][c] == 'B')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] == 'R')
            break ;
    }

    // check for pieces that can capture from diagonally down-leftward: Q, B, & P.
    r = k_row;
    c = k_col;
    while (++r <= r_max && --c >= 0)
    {
        if (c == k_col - 1 && r == k_row + 1 && board[r][c] == 'P')
        {
puts("\tPawn checkmate! From down-left.");
            return (1);
        }
        else if (board[r][c] == 'Q' || board[r][c] == 'B')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] == 'R')
            break ;
    }
puts("No checkmate diagonally");
    return (0);
}

int     check_ortho(char **board, int r_max, int c_max, int k_row, int k_col)
{
    int r = k_row;
    int c = k_col;

    // check down from King's position
    while (r <= r_max)
    {
        if (board[r][c] == 'Q' || board[r][c] == 'R')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] == 'B')
            break ;
        r++;
    }

    // check up from King's position
    r = k_row;
    while (r >= 0)
    {
        if (board[r][c] == 'Q' || board[r][c] == 'R')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] == 'B')
            break ;
        r--;
    }

    // check right from King's position
    r = k_row;
    while (c <= c_max)
    {
        if (board[r][c] == 'Q' || board[r][c] == 'R')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] == 'B')
            break ;
        c++;
    }

    // check left from King's position
    c = k_col;
    while (c >= 0)
    {
        if (board[r][c] == 'Q' || board[r][c] == 'R')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] == 'B')
            break ;
        c--;
    }
puts("No checkmate orthogonally");
    return (0);
}

int     get_kcol(char *row)
{
    int col = 0;

    while (row[col])
    {
        if (row[col] == 'K')
            return (col);
        col++;
    }
    return (-1);
}

int     get_krow(char **board, int r_max)
{
    int row, col;

    row = 0;
    while (row <= r_max)
    {
        col = 0;
        while (board[row][col])
        {
            if (board[row][col] == 'K')
                return (row);
            col++;
        }
        row++;
    }
    return (-1);
}

int     main(int ac, char **av)
{
    char **board;
    int row_max, col_max, k_row, k_col;

    if (ac < 2)
        return (write(1, "\n", 1));

    board = &av[1];
    
    row_max = ac - 2;
    col_max = row_max;

    k_row = get_krow(board, row_max);
    k_col = get_kcol(board[k_row]);

printf("King's position: [%d][%d]\n", k_row, k_col);

    if (check_ortho(board, row_max, col_max, k_row, k_col) == 1)
        return (write(1, "Success\n", 8));
    else if (check_diag(board, row_max, col_max, k_row, k_col) == 1)
        return (write(1, "Success\n", 8));
    else
        return (write(1, "Fail\n", 5));
    
    return (0);
}