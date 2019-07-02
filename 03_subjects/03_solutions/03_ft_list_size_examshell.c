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


// for testing ONLY
void    print_list(t_list *lst)
{
    int size = 0;
    while (lst)
    {
        size++;
        lst = lst->next;
    }
}

int     main(void)
{
    t_list *lst;
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;

    lst = (t_list *)malloc(sizeof(t_list));
    lst->data = &a;
    lst->next = (t_list *)malloc(sizeof(t_list));
    lst->next->data = &b;
    lst->next->next = (t_list *)malloc(sizeof(t_list));
    lst->next->next->data = &c;
    lst->next->next->next = (t_list *)malloc(sizeof(t_list));
    lst->next->next->next->data = &d;
    lst->next->next->next->data = NULL;

    print_list(lst);
    printf("\n");
    printf("list size: %d\n", ft_list_size(lst));
    return (0);
}