/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:44:52 by mayilmaz          #+#    #+#             */
/*   Updated: 2025/01/22 17:09:04 by mayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_rotate(t_list **head, char c)
{
	t_list	*first;
	t_list	*last;

	first = (*head);
	last = (*head);
	(*head) = first->next;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	ft_reverse_rotate(t_list **head, char c)
{
	t_list	*node;
	t_list	*last;
	t_list	*tmp;

	node = (*head);
	last = (*head);
	while (last->next->next != NULL)
		last = last->next;
	tmp = last->next;
	tmp->next = node;
	last->next = NULL;
	(*head) = tmp;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}
