/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:43:57 by mayilmaz          #+#    #+#             */
/*   Updated: 2025/01/22 18:13:28 by mayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

void	ft_error_arg(char **str, int ac)
{
	if (ac == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (ac == 2)
	{
		free_split(str, ft_strlen(str));
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	ft_free_last(char	**str, t_list	**stack, int ac)
{
	t_list	*tmp;

	tmp = (*stack);
	while ((*stack))
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		free(tmp);
	}
	if (ac == 2)
		free_split(str, ft_strlen(str));
}

void	ft_error_node(char	**str, t_list	**stack, int ac)
{
	ft_free_last(str, stack, ac);
	write(2, "Error\n", 6);
	exit(1);
}
