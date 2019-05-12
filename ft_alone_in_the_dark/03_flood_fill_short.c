typedef struct 	s_point
{
	int			x;
	int			y;
}				t_point;

void	recur(char **tab, t_point size, t_point begin, char key)
{
	if (begin.x < 0 || begin.x >= size.x ||
		begin.y < 0 || begin.y >= size.y ||
		tab[begin.y][begin.x] != key)
		return;
	tab[begin.y][begin.x] = 'F';
	recur(tab, size, (t_point){begin.x - 1, begin.y}, key);
	recur(tab, size, (t_point){begin.x + 1, begin.y}, key);
	recur(tab, size, (t_point){begin.x, begin.y - 1}, key);
	recur(tab, size, (t_point){begin.x, begin.y + 1}, key);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	recur(tab, size, begin, tab[begin.y][begin.x]);
}
