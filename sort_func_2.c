#include "push_swap.h"

void	ft_three_sort(t_list	**head)
{
	if ((*head)->num > (*head)->next->num)
	{
		if ((*head)->next->num > (*head)->next->next->num)
		{
			ft_swap(head, 'a');
			ft_reverse_rotate(head, 'a');
		}
		else if ((*head)->num > (*head)->next->next->num)
			ft_rotate(head, 'a');
		else if ((*head)->next->next->num > (*head)->num)
			ft_swap(head, 'a');
	}
	else if (((*head)->next->num > (*head)->num))
	{
		if ((*head)->num > (*head)->next->next->num)
			ft_reverse_rotate(head, 'a');
		else if ((*head)->next->num > (*head)->next->next->num)
		{
			ft_reverse_rotate(head, 'a');
			ft_swap(head, 'a');
		}
	}
}

void	ft_two_sort(t_list	**head)
{
	if((*head)->index < (*head)->next->index)
		ft_swap(head, 'b');
}
