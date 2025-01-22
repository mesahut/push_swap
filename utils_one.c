/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:44:03 by mayilmaz          #+#    #+#             */
/*   Updated: 2025/01/22 17:45:32 by mayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	ft_atoi(char	**av, char *str, t_list	**stack, int ac)
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
			ft_error_node(av, stack, ac);
		i++;
	}
	return (number);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_is_valid(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if ((str[i][j] == 45 || str[i][j] == 43))
			j++;
		while (str[i][j])
		{
			if (((str[i][j] > '9') || (str[i][j] < '0')))
				ft_error_arg(str, 2);
			j++;
		}
		i++;
	}
}

void	ft_is_unique(char	**str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) == 0)
			{
				ft_error_arg(str, 2);
			}
			j++;
		}
		i++;
	}
}

void	ft_is_valid_and_unique(char **str, int ac)
{
	if (str == NULL || *str == NULL)
	{
		ft_error_arg(str, 0);
	}
	if (ac > 2)
	{
		str++;
		ft_is_valid(str);
		ft_is_unique(str);
	}
	else
	{
		ft_is_valid(str);
		ft_is_unique(str);
	}
}
