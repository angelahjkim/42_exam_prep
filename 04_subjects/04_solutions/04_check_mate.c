#include <unistd.h>

int     check_ortho(char **board, int k_row, int k_col, int r_max, int c_max)
{
    int r = k_row;
    int c = k_col;

    while (c >=0)
    {
        if (board[r][c] == 'R' || board[r][c] == 'Q')
            return (1);
        else if (board[r][c] == 'B' || board[r][c] == 'P')
            break ;
        c--;
    }

    r = k_row;
    c = k_col;
    while (c <= c_max)
    {
        if (board[r][c] == 'R' || board[r][c] == 'Q')
            return (1);
        else if (board[r][c] == 'B' || board[r][c] == 'P')
            break ; 
        c++;
    }

    r = k_row;
    c = k_col;
    while (r >= 0)
    {
        if ()   // CONTINUE HERE
        r--;
    }
}

int     check_diag(char **board, int k_row, int k_col, int r_max, int c_max)
{
    int r = k_row;
    int c = k_col;

    // diagonal up-left
    while (--c >= 0 && --r >= 0)
    {
        if (board[r][c] == 'Q' || board[r][c] == 'B')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] == 'B')
            break ;
    }

    // diagonal up-right
    r = k_row;
    c = k_col;
    while (++c <= c_max && --r >= 0)
    {
        if (board[r][c] == 'Q' || board[r][c] == 'B')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] == 'B')
            break ; 
    }

    // diagonal down-left (pawn)
    r = k_row;
    c = k_col;
    while (--c >= 0 && ++r <= r_max)
    {
        if (c == k_col - 1 && r == k_row + 1 && board[r][c] == 'P')
            return (1);
        else if (board[r][c] == 'B' || board[r][c] == 'Q')
            return (1);
        else if (board[r][c] == 'P' || board[r][c] == 'R')
            break ;
    }

    // diagonal down-right (pawn)
    r = k_row;
    c = k_col;
    while (++c <= c_max && ++r <= r_max)
    {
        if (c == k_col + 1 && r == k_row + 1 && board[r][c] == 'P')
            return (1);
        else if (board[r][c] == 'B' || board[r][c] == 'Q')
            return (1);
        else if (board[r][c] == 'R' || board[r][c] == 'P')
            break ;
    }

    return (0);
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
    k_col = get_kcol(board[k_row);

    if (check_ortho(board, k_row, k_col, row_max, col_max))
        return (write(1, "Success\n", 8));
    else if (check_diag(board, k_row, k_col, row_max, col_max))
        return (write(1, "Success\n", 8));
    else
        return (write(1, "Fail\n", 5));

    return (0);
}