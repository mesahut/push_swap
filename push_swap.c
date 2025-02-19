/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:45:03 by mayilmaz          #+#    #+#             */
/*   Updated: 2025/02/19 01:22:29 by mayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	create_node(t_list **head, int data, char **str)
{
	t_list	*new_node;
	t_list	*current;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
	{
		ft_error_node(str, head);
	}
	new_node->num = data;
	new_node->index = 0;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

void	ft_stack_processor(t_list	**stack_a, t_list	**stack_b)
{
	int	node_size;

	node_size = ft_list_size(stack_a);
	if (node_size == 2)
		ft_two_sort(stack_a);
	else if (node_size == 3)
		ft_three_sort(stack_a);
	else if (node_size > 3)
	{
		ft_sort_in_b(stack_a, stack_b);
		ft_three_sort(stack_a);
		ft_last_sort(stack_a, stack_b);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		i;
	char	**tmp;

	a = NULL;
	b = NULL;
	i = 1;
	tmp = NULL;
	if (ac < 2)
		return (0);
	ft_error_check(&a, tmp, av, i);
	ft_get_index(&a);
	ft_stack_processor(&a, &b);
	ft_free_last(&a);
	return (1);
}
