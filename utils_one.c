/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:44:03 by mayilmaz          #+#    #+#             */
/*   Updated: 2025/02/18 23:20:23 by mayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	ft_atoi(char	**av, char *str, t_list	**stack)
{
	int			i;
	long int	number;
	int			negative;

	i = 0;
	number = 0;
	negative = 1;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			negative *= -1;
		i++;
	}
	while ((str[i] >= 48 && str[i] <= 57) && str[i])
	{
		number *= 10;
		number += str[i] - 48;
		if (number >= 0 && number < 10)
			number *= negative;
		if ((number > 2147483647) || (number < -2147483648))
			ft_error_node(av, stack);
		i++;
	}
	return (number);
}

void	ft_is_valid(char **str, t_list **stack)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if ((str[i][j] == 45 || str[i][j] == 43))
			j++;
		if (!str[i][j])
		{
			free_split(str, ft_strlen(str));
			ft_error_arg(stack);
		}
		while (str[i][j])
		{
			if (((str[i][j] > '9') || (str[i][j] < '0')))
			{
				free_split(str, ft_strlen(str));
				ft_error_arg(stack);
			}
			j++;
		}
		i++;
	}
}

void	ft_is_unique(t_list **stack)
{
	t_list	*node;
	t_list	*check;

	node = (*stack);
	while (node->next)
	{
		check = node->next;
		while (check)
		{
			if (node->num == check->num)
				ft_error_arg(stack);
			check = check->next;
		}
		node = node->next;
	}
}
