/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:44:27 by mayilmaz          #+#    #+#             */
/*   Updated: 2025/02/19 02:21:33 by mayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_list_size(t_list	**head)
{
	t_list	*node;
	int		i;

	node = (*head);
	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

void	ft_move_big_node(t_list **head_b, int step)
{
	int	new_step;

	new_step = ft_optimize_move(head_b, step);
	if (step > new_step)
	{
		while (new_step != 0)
		{
			ft_reverse_rotate(head_b, 'b');
			new_step--;
		}
	}
	else
	{
		while (step != 0)
		{
			ft_rotate(head_b, 'b');
			step--;
		}
	}
}

void	ft_make_head_in_b(t_list	**head_b, int index_a)
{
	int	len;
	int	pla_b;
	int	new_pla_b;

	len = 0;
	pla_b = 0;
	new_pla_b = 0;
	pla_b = ft_place_in_b(head_b, index_a, pla_b, len);
	new_pla_b = ft_optimize_move(head_b, pla_b);
	if (new_pla_b < pla_b)
		ft_move(head_b, new_pla_b, 'r', 'b');
	else
		ft_move(head_b, pla_b, 'd', 'b');
}

void	ft_move(t_list **head, int cost_size, char op, char stack)
{
	while (cost_size != 0)
	{
		if (stack == 'a')
		{
			if (op == 'r')
				ft_reverse_rotate(head, stack);
			else
				ft_rotate(head, stack);
		}
		else if (stack == 'b')
		{
			if (op == 'r')
				ft_reverse_rotate(head, stack);
			else
				ft_rotate(head, stack);
		}
		cost_size--;
	}
}
