/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:44:37 by mayilmaz          #+#    #+#             */
/*   Updated: 2025/01/22 17:06:25 by mayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	ft_swap(t_list **head, char c)
{
	t_list	*node;
	t_list	*tmp;

	node = (*head);
	tmp = node->next;
	node->next = node->next->next;
	tmp->next = node;
	(*head) = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}
