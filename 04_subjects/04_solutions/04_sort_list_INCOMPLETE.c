// for testing ONLY
#include "list.h"

int		croissant(int a, int b)
{
	if (a <= b) //1 < 2 = 1
		return (1);
	else // 2 > 1 = 0
		return (0);
}
// end of TESTING

int		tri(t_list *lst, int (*cmp)(int, int))
{
	while (lst->next)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_list 	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *first;
	int swap;

	swap = 0;
	first = lst;
	while (tri(first, cmp) == 0)
	{
		lst = first;
		while (lst->next)
		{
			if ((*cmp)(lst->data, lst->next->data) == 0)
			{
				swap = lst->data;
				lst->data = lst->next->data;
				lst->next->data = swap;	
			}
			lst = lst->next;
		}
	}
	return (first);
}


// for testing ONLY
#include <stdio.h>
#include <stdlib.h>

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("[%d]", lst->data);
		lst = lst->next;
	}
	printf("\n");
}

int main(void)
{
	t_list *lst;
	
	lst = (t_list*)malloc(sizeof(t_list));
	lst->data = 20;
	lst->next = (t_list*)malloc(sizeof(t_list));
	lst->next->data = 10;
	lst->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->data = 0;
	lst->next->next->next = NULL;

	print_list(lst);

	lst = sort_list(lst, croissant);

	print_list(lst);

	return (0);
}