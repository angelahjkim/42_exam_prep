typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

#include <stdio.h>


void	print_tab(char **tab, t_point size)
{
	int i = 0;
	int j;

	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			printf("%c", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	recur(char **tab, t_point size, t_point begin, char to_fill)
{
	if (tab[begin.y][begin.x] != to_fill)
		return ;

	tab[begin.y][begin.x] = 'F';

	if (begin.y > 0)
	{
		begin.y--;
		recur(tab, size, begin, to_fill);
		begin.y++;
	}


	if (begin.x > 0)
	{
		begin.x--;
		recur(tab, size, begin, to_fill);
		begin.x++;
	}


	if (begin.y < size.y - 1)
	{
		begin.y++;
		recur(tab, size, begin, to_fill);
		begin.y--;
	}


	if (begin.x < size.x - 1)
	{
		begin.x++;
		recur(tab, size, begin, to_fill);
		begin.x--;
	}

//	printf("\n\nTable:\n");
//	print_tab(tab, size);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	recur(tab, size, begin, tab[begin.y][begin.x]);
}

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	//char **area;
	t_point size = {8, 5};
	t_point begin = {0, 0};

		char **tab = malloc(sizeof(char *) * size.y);
		tab[0] = strdup("11111111");
		tab[1] = strdup("10001001");
		tab[2] = strdup("10010001");
		tab[3] = strdup("10110001");
		tab[4] = strdup("11100001");


	//static char *zone[] = {
	//	"11111111",
	//	"10001001",
	//	"10010001",
	//	"10110001",
	//	"11100001",
	//};


	//print_tab(area);
	flood_fill(tab, size, begin);
	write(1, "\n", 1);



	print_tab(tab, size);
	return (0);
}
