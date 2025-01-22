/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:44:56 by mayilmaz          #+#    #+#             */
/*   Updated: 2025/01/22 18:20:04 by mayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	push_b(t_list	**head_a, t_list	**head_b)
{
	t_list	*tmp;
	t_list	*node_b;

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
