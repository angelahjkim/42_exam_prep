#include "flood_fill.h"

void	fill(char **tab, t_point size, t_point begin, char to_fill)
{
	if (tab[begin.y][begin.x] != to_fill)
		return ;
	
	tab[begin.y][begin.x] = 'F';

	if (begin.y < size.y - 1)
	{
		begin.y++;
		fill(tab, size, begin, to_fill);
		begin.y--;
	}

	if (begin.x < size.x - 1)
	{
		begin.x++;
		fill(tab, size, begin, to_fill);
		begin.x--;
	}

	if (begin.y > 0)
	{
		begin.y--;
		fill(tab, size, begin, to_fill);
		begin.y++;
	}

	if (begin.x > 0)
	{
		begin.x--;
		fill(tab, size, begin, to_fill);
		begin.x++;
	}
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

// for testing  ONLY

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_tab(char **area)
{
	int i, j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 8)
		{
			ft_putchar(area[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

char	**make_area(char **zone)
{
	int i;
	int j;
	char **p;

	p = (char **)malloc(sizeof(char *) * 5);
	i = 0;
	while (i < 5)
	{
		p[i] = (char *)malloc(sizeof(char) * 8);
		j = 0;
		while (zone[i][j])
		{
			p[i][j] = zone[i][j];
			j++;
		}
		i++;
	}
	return (p);
}

int		main(void)
{
    char **area;
    t_point size = {8, 5};
    t_point begin = {0, 0};
    char *zone[] = {
        "11111111",
        "10001001",
        "10010001",
        "10110001",
        "11100001"
    };
 
    area = make_area(zone);
    print_tab(area);
    flood_fill(area, size, begin);
	ft_putchar('\n');
    print_tab(area);
 
    return (0);
}