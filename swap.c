#include <unistd.h>
#include "push_swap.h"


void	ft_swap(t_list **head, char c)
{
	t_list *node = *head;
	t_list *tmp;

	tmp = node->next;
	node->next = node->next->next;
	tmp->next = node;
	head = tmp;
	if(c == 'a')
		write(1, "sa\n", 3);
	if(c == 'b')
		write(1, "sb\n", 3);
}

void	ft_swap_ss(t_list	**head_a, t_list **head_b)
{
	ft_swap(&head_a, 's');
	ft_swap(&head_b, 's');
	write(1, "ss\n", 3);
}