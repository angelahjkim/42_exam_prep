/*
** FT_LIST_SIZE: Write a function that returns the number of elements in the
** linked list that's passed to it.
*/

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int size = 0;

	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

// for testing -- INCOMPLETE...
#include <stdlib.h>
int		main(void)
{
	t_list *list;
	t_list *node;
	int i;
	int size = 3;
	char *str = "hello";
	
	list = (t_list *)malloc(sizeof(t_list));
	list->data = (char *)str;
	i = 0;
	while (i < size)
	{
		node = (t_list *)malloc(sizeof(t_list));
		node->data = (char *)str;
		list->next = node;
		free((void **)&node);
		i++;
	}
	return (0);
}
