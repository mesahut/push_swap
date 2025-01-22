/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:44:40 by mayilmaz          #+#    #+#             */
/*   Updated: 2025/01/22 17:22:15 by mayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_index(t_list **head_a)
{
	t_list	*node;
	t_list	*current;
	t_list	*tmp;
	int		i;

	i = 0;
	node = (*head_a);
	current = (*head_a);
	while (node)
	{
		i++;
		current = (*head_a);
		while (current->index != 0)
			current = current->next;
		tmp = current;
		while (current)
		{
			if ((tmp->num > current->num) && (current->index == 0))
				tmp = current;
			current = current->next;
		}
		tmp->index = i;
		node = node->next;
	}
}

void	ft_last_sort(t_list	**head_a, t_list	**head_b)
{
	t_list	*last_big;
	int		count;

	last_big = (*head_a);
	count = 0;
	while ((*head_b))
	{
		last_big = (*head_a);
		while (last_big->next)
			last_big = last_big->next;
		while ((count < 3) && ((last_big->index > (*head_b)->index)))
		{
			ft_reverse_rotate(head_a, 'a');
			last_big = (*head_a);
			while (last_big->next)
				last_big = last_big->next;
			count++;
		}
		push_a(head_a, head_b);
	}
	while (count++ < 3)
		ft_reverse_rotate(head_a, 'a');
}

void	ft_sort_in_b(t_list	**head_a, t_list	**head_b)
{
	t_list	*min_cost;
	int		head_cost;

	head_cost = 0;
	while ((*head_a)->next->next->next)
	{
		min_cost = ft_less_cost(head_a, head_b);
		ft_make_head_in_b(head_b, min_cost->index);
		ft_push_min(head_a, head_b, min_cost->index);
	}
	head_cost = ft_find_max(head_b);
	ft_move_big_node(head_b, head_cost);
}

void	ft_push_min(t_list **head_a, t_list **head_b, int min_index)
{
	t_list	*node_a;
	int		cost_min;

	cost_min = 0;
	node_a = (*head_a);
	while (node_a)
	{
		if (node_a->index == min_index)
			break ;
		cost_min++;
		node_a = node_a->next;
	}
	ft_move(head_a, cost_min, 'd', 'a');
	push_b(head_a, head_b);
}
