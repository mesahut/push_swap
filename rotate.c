#include "push_swap.h"
#include <stddef.h>
#include <unistd.h>

void	ft_rotate(t_list **head, char c)
{
	t_list *first;
	t_list *last;

	first = (*head);
	last = (*head);
	(*head) = first->next;
	while(last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if(c == 'a')
		write(1, "ra\n", 3);
	if(c == 'b')
		write(1, "rb\n", 3);
}

void ft_reverse_rotate(t_list **head, char c)
{
	t_list *node;
	t_list *last;
	t_list *tmp;

	node = (*head);
	last = (*head);

	while (last->next->next != NULL)
		last = last->next;
	tmp = last->next;
	tmp->next = node;
	last->next = NULL;
	(*head) = tmp;
	if(c == 'a')
		write(1, "rra\n", 4);
	if(c == 'b')
		write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_rrr(t_list **head_a, t_list **head_b)
{
	ft_reverse_rotate(head_a, 'r');
	ft_reverse_rotate(head_b, 'r');
	write(1, "rrr\n", 4);
}

void ft_rotate_rr(t_list **head_a, t_list **head_b)
{
	ft_rotate(head_a, 'r');
	ft_rotate(head_b, 'r');
	write(1, "rr\n", 3);
}