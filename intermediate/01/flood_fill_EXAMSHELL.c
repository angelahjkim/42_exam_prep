#include "flood_fill.h"

void	fill_recur(char **tab, t_point size, t_point begin, char to_fill)
{
	if (tab[begin.y][begin.x] != to_fill)
		return ;

	tab[begin.y][begin.x] = 'F';

	if (begin.y < size.y - 1)
	{
		++begin.y;
		fill_recur(tab, size, begin, to_fill);
		--begin.y;
	}

	if (begin.x < size.x - 1)
	{
		++begin.x;
		fill_recur(tab, size, begin, to_fill);
		--begin.x;
	}

	if (begin.y > 0)
	{
		--begin.y;
		fill_recur(tab, size, begin, to_fill);
		++begin.y;
	}

	if (begin.x > 0)
	{
		--begin.x;
		fill_recur(tab, size, begin, to_fill);
		++begin.x;
	}

}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill_recur(tab, size, begin, tab[begin.y][begin.x]);
}