#include <stdlib.h>
#include "ft_list.h"

// for testing ----
int     cmp(void *data_ref, void *data)
{
    int *a = data;
    int *b = data_ref;

    if (*a == *b)
        return (0);
    return (1);
}
// DELETE after testing ----


void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list  *lst;
    t_list  *tmp;
    int     i;

    if (begin_list == NULL || *begin_list == NULL)
        return ;
    
    tmp = *begin_list;
    while (cmp(data_ref, (*begin_list)->data) == 0)
    {
        tmp = (*begin_list)->next;
        free(*begin_list);
        *begin_list = tmp;
    }
    
    lst = *begin_list;
    tmp = *begin_list;
    i = 0;
    while (lst)
    {
        if (cmp(data_ref, lst->data) == 0)
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


// for testing -----
#include <stdio.h>

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
    t_list  *lst;
    int     a = 1;
    int     b = 2;
    int     c = 3;
    int     d = 2;

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