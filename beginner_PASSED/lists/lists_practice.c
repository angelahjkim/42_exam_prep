#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int	data;
	struct s_list *next;
}				t_list;

void	ft_newlst(t_list **head, int data)
{
	t_list *new = (t_list *)malloc(sizeof(t_list));
	new->data = data;
	new->next = *head;
	*head = new;
}

void ft_print(t_list **h)
{
	while (*h)
	{
		printf("%d\n", (*h)->data);
		*h = (*h)->next;
	}
}

int main(void)
{
	t_list **lst;

	lst = (t_list **)malloc(sizeof(t_list *));
	ft_newlst(lst, 100);
	ft_newlst(lst, 42);
	ft_newlst(lst, 3);

	ft_print(lst);
	free (lst);
}
