#include <stdlib.h>
#include "ft_list.h"

// for testing
#include <stdio.h>
int     cmp(void *data, void *data_ref)
{
    int *a = data;
    int *b = data_ref;

    if (*a == *b)
        return (0);
    return (1);
}
// DELETE after testing ----


void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *lst;
	t_list *tmp;
	int i = 0;

    // check if begin_list (head) and *begin_list (first list element) have a valid address memory
	if (begin_list == NULL || *begin_list == NULL)
		return ;

    // go through fist element of *begin_list and if data is equal to data_ref, free that element
    // and continue traversing list and freeing while data is equal to data_ref
	tmp = *begin_list;
	while ((*cmp)((*begin_list)->data, data_ref) == 0)
	{
		tmp = (*begin_list)->next;
		free(*begin_list);
		(*begin_list) = tmp;
	}

    // traverse through list, removing elements and changing the links as necessary around the
    // deleted element(s)
	lst = *begin_list;
	tmp = *begin_list;
	while (lst != NULL)
	{
		if ((*cmp)(lst->data, data_ref) == 0)
		{
			tmp->next = lst->next;
			free(lst);
			lst = tmp;
			i = 0;
		}
		if (i > 0)
			tmp = tmp->next;
		if (lst != NULL)
			lst = lst->next;
		i++;
	}
}


// for testing -------
void    print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d\n", *(int *)lst->data);
        lst = lst->next;
    }
}

int     main(void)
{
    t_list *lst;
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 2;

    lst = (t_list *)malloc(sizeof(t_list));
    lst->data = &a;

    lst->next = (t_list *)malloc(sizeof(t_list));
    lst->next->data = &b;

    lst->next->next = (t_list *)malloc(sizeof(t_list));
    lst->next->next->data = &c;

    lst->next->next->next = (t_list *)malloc(sizeof(t_list));
    lst->next->next->next->data = &d;
    lst->next->next->next->next = NULL;

    print_list(lst);
    printf("\n");
    ft_list_remove_if(&lst, &b, cmp);
    print_list(lst);

    return (0);
}