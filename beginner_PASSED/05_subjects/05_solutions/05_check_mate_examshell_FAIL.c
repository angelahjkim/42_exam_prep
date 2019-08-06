/*

TEST CASE : '........' '........' '.P....P.' '...B.B..' '....Q...' '..R..R..' '......K.' '...R....'

FAILED ON EXAMSHELL

*/

#include <unistd.h>

int		check_diag(char **board, int k_row, int k_col, int r_max, int c_max)
{
	int r = k_row;
	int c = k_col;

	while (++r <= r_max && ++c <= c_max)
	{
		if (r == k_row + 1 && c == k_col + 1 && board[r][c] == 'P')
			return (1);
		else if (board[r][c] == 'Q' || board[r][c] == 'B')
			return (1);
		else if (board[r][c] == 'R')
			break ;
	}

	r = k_row;
	c = k_col;
	while (++r <= r_max && --c >= 0)
	{
		if (r == k_row + 1 && c == k_col - 1 && board[r][c] == 'P')
			return (1);
		else if (board[r][c] == 'Q' || board[r][c] == 'B')
			return (1);
		else if (board[r][c] == 'R')
			break ;
	}

	r = k_row;
	c = k_col;
	while (--r >= 0 && ++c <= c_max)
	{
		if (board[r][c] == 'Q' || board[r][c] == 'B')
			return (1);
		else if (board[r][c] == 'B' || board[r][c] == 'P')
			break ;
	}

	r = k_row;
	c = k_col;
	while (--r >= 0 && --c >= 0)
	{
		if (board[r][c] == 'Q' || board[r][c] == 'B')
			return (1);
		else if (board[r][c] == 'B' || board[r][c] == 'P')
			break ;
	}

	return (0);
}

int		check_ortho(char **board, int k_row, int k_col, int r_max, int c_max)
{
	int r = k_row;
	int c = k_col;

	while (--r >= 0)
	{
		if (board[r][c] == 'Q' || board[r][c] == 'R')
			return (1);
		else if (board[r][c] == 'B' || board[r][c] == 'P')
			break ;
	}

	r = k_row;
	c = k_col;
	while (++r <= r_max)
	{
		if (board[r][c] == 'Q' || board[r][c] == 'R')
			return (1);
		else if (board[r][c] == 'B' || board[r][c] == 'P')
			break ;
	}

	r = k_row;
	c = k_col;
	while (--c >= 0)
	{
		if (board[r][c] == 'Q' || board[r][c] == 'R')
			return (1);
		else if (board[r][c] == 'B' || board[r][c] == 'P')
			break ;
	}

	r = k_row;
	c = k_col;
	while (++c <= c_max)
	{
		if (board[r][c] == 'Q' || board[r][c] == 'R')
			return (1);
		else if (board[r][c] == 'B' || board[r][c] == 'P')
			break ;
	}

	return (0);
}

int		get_kcol(char *board_row)
{
	int i = 0;
	while (board_row[i])
	{
		if (board_row[i] == 'K')
			return (i);
		i++;
	}
	return (-1);
}

int		get_krow(char **board, int r_max)
{
	int i, j;

	i = 0;
	while (i <= r_max)
	{
		j = 0;
		while (board[i][j])
		{
			if (board[i][j] == 'K')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int		main(int ac, char **av)
{
	int k_row, k_col, r_max, c_max;
	char **board;

	if (ac < 2)
		return (write(1, "\n", 1));

	board = &av[1];
	r_max = ac - 2;
	c_max = r_max;
	k_row = get_krow(board, r_max);
	k_col = get_kcol(board[k_row]);

	if (check_ortho(board, k_row, k_col, r_max, c_max) == 1)
		return (write(1, "Success\n", 8));
	else if (check_diag(board, k_row, k_col, r_max, c_max) == 1)
		return (write(1, "Success\n", 8));
	else
		return (write(1, "Fail\n", 5));

	return (0);
}