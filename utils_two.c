/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 23:58:55 by mayilmaz          #+#    #+#             */
/*   Updated: 2025/02/19 02:21:54 by mayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_is_sortted(t_list **head_a)
{
	t_list	*node;

	node = (*head_a);
	while (node->next != NULL)
	{
		if (node->num > node->next->num)
			return (0);
		node = node->next;
	}
	return (1);
}

void	ft_error_check(t_list **a, char **tmp, char **av, int i)
{
	int	j;

	j = 0;
	while (av[i])
	{
		j = 0;
		tmp = ft_split(av[i], ' ');
		if (!tmp)
			ft_error_arg(a);
		while (tmp[j])
		{
			ft_is_valid(tmp, a);
			create_node(a, ft_atoi(tmp, tmp[j], a), tmp);
			j++;
		}
		i++;
		free_split(tmp, ft_strlen(tmp));
	}
	ft_is_unique(a);
	if ((ft_is_sortted(a)))
	{
		ft_free_last(a);
		exit(1);
	}
}
