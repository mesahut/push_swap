#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>


void	push_b(t_list	**head_a, t_list	**head_b)
{
	t_list *tmp;
	t_list *node_b;
	tmp = (*head_a);
	node_b = (*head_b);
	(*head_a) = (*head_a)->next;
	tmp->next = node_b;
	(*head_b) = tmp;
	write(1, "pb\n", 3);
}

void	push_a(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;
	t_list	*node_a;
	tmp = (*head_b);
	node_a = (*head_a);
	(*head_b) = (*head_b)->next;
	tmp->next = node_a;
	(*head_a) = tmp;
	write(1, "pa\n", 3);
}