#include "lst.h"
#include <stdlib.h>

t_list	*lst_new(int data)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	new->data = data;
	new->next = NULL;
	return (new);
}
