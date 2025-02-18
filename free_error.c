/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:43:57 by mayilmaz          #+#    #+#             */
/*   Updated: 2025/02/19 01:23:09 by mayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

void	ft_error_arg(t_list **stack)
{
	ft_free_last(stack);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_last(t_list	**stack)
{
	t_list	*tmp;

	tmp = (*stack);
	while ((*stack))
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		free(tmp);
	}
}

void	ft_error_node(char	**str, t_list	**stack)
{
	ft_free_last(stack);
	free_split(str, ft_strlen(str));
	write(2, "Error\n", 6);
	exit(1);
}
