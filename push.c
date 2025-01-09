#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>


void	push_create(t_list **head, int num)
{
	t_list *node;
	t_list *new_node;
	node = *head;
	new_node = (t_list *)malloc(sizeof(t_list));
	if(!new_node)
		return;
	new_node->num = num;
	new_node->next = node;
	head = new_node;
}

void	push_b(t_list	**head_a, t_list	**head_b)
{
	t_list *tmp;
	push_create(head_b, (*head_a)->num);
	tmp = (*head_a)->next;
	free(head_a);
	(*head_a) = tmp;
	write(1, "pb\n", 3);
}

void	push_a(t_list **head_a, t_list **head_b)
{
	t_list *tmp;

	push_create(head_a, (*head_b)->num);
	tmp = (*head_b)->next;
	free(head_b);
	(*head_b) = tmp;
	write(1, "pa\n", 3);
}