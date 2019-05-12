typedef struct 		s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

#include <stdlib.h>
#include <stdio.h>

void	print_lst(t_list **lst)
{
	while (*lst)
	{
		printf("%d\n", (*lst)->data);
		*lst = (*lst)->next;
	}
}

void	new_elem(t_list **lst, int data)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	new->data = data;
	new->next = *lst;
	*lst = new;
}

int		main(void)
{
	t_list **lst;
	t_list *new;

	lst = (t_list **)malloc(sizeof(t_list *));
	new_elem(lst, 3);
	new_elem(lst, 42);
	new_elem(lst, 100);

	print_lst(lst);
	free(lst);

	return (0);
}
