#include "flood_fill.h"	// for TESTING ONLY (include flood_fill function prototype)



void	fill(char **tab, t_point size, int x, int y, char c)
{
	if (y < 0 || x < 0 || y >= size.y || x >= size.x)
		return ;
	if (tab[y][x] == c)
	{
		tab[y][x] = 'F';
		fill(tab, size, x, y - 1, c);
		fill(tab, size, x - 1, y, c);
		fill(tab, size, x, y + 1, c);
		fill(tab, size, x + 1, y, c);
	}
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char c;

	begin.y--;
	begin.x--;

	c = tab[begin.y][begin.x];
	fill(tab, size, begin.x, begin.y, c);
}





// for testing
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_tab(char **area)
{
	int i;
	int j;

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
    t_point begin = {0, 1};
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
    print_tab(area);
    return (0);
}
