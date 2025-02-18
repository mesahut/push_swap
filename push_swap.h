/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:44:59 by mayilmaz          #+#    #+#             */
/*   Updated: 2025/02/19 01:25:37 by mayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*next;

}	t_list;

int		ft_place_in_b(t_list **head_b, int index_a, int pla_b, int len);
void	ft_error_check(t_list **a, char **tmp, char **av, int i);
void	ft_push_min(t_list **head_a, t_list **head_b, int min_index);
void	ft_move(t_list **head, int cost_size, char op, char stack);
int		ft_count_cost(t_list **head_b, int index_a, int pla_a);
void	create_node(t_list **head, int data, char **str);
t_list	*ft_less_cost(t_list **head_a, t_list **head_b);
void	ft_make_head_in_b(t_list **head_b, int index_a);
void	ft_sort_in_b(t_list **head_a, t_list **head_b);
void	ft_last_sort(t_list **head_a, t_list **head_b);
int		ft_atoi(char **av, char *str, t_list **stack);
void	ft_move_big_node(t_list **head_b, int step);
int		ft_optimize_move(t_list **head, int place);
void	ft_error_node(char **str, t_list **stack);
void	push_b(t_list **head_a, t_list **head_b);
void	push_a(t_list **head_a, t_list **head_b);
void	ft_reverse_rotate(t_list **head, char c);
void	ft_is_valid(char **str, t_list **stack);
char	**ft_split(char const *s, char c);
void	ft_rotate(t_list **head, char c);
void	ft_swap(t_list **head, char c);
void	ft_get_index(t_list **head_a);
void	ft_free_last(t_list **stack);
void	ft_is_unique(t_list **stack);
void	ft_three_sort(t_list **head);
int		ft_find_max(t_list **head_b);
void	ft_error_arg(t_list **stack);
void	free_split(char **f, int k);
int		ft_list_size(t_list **head);
void	ft_two_sort(t_list **head);
int		ft_strlen(char **s);

#endif
