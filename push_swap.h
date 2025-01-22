/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayilmaz <mayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:44:59 by mayilmaz          #+#    #+#             */
/*   Updated: 2025/01/22 17:43:21 by mayilmaz         ###   ########.fr       */
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

int		ft_count_cost(t_list **head_b, int index_a, int pla_a);
int		ft_place_in_b(t_list **head_b, int index_a, int pla_b, int len);
void	ft_push_min(t_list **head_a, t_list **head_b, int min_index);
void	ft_move(t_list **head, int cost_size, char op, char stack);
void	ft_reverse_rotate_rrr(t_list **head_a, t_list **head_b);
t_list	*ft_less_cost(t_list **head_a, t_list **head_b);
int		ft_atoi(char **av, char *str, t_list **stack, int ac);
void	ft_free_last(char **str, t_list **stack, int ac);
void	ft_error_node(char **str, t_list **stack, int ac);
void	ft_make_head_in_b(t_list **head_b, int index_a);
void	ft_sort_in_b(t_list **head_a, t_list **head_b);
void	ft_last_sort(t_list **head_a, t_list **head_b);
void	ft_swap_ss(t_list **head_a, t_list **head_b);
void	ft_rotate_rr(t_list **head_a, t_list **head_b);
void	ft_move_big_node(t_list **head_b, int step);
void	ft_is_valid_and_unique(char **str, int ac);
int		ft_optimize_move(t_list **head, int place);
void	push_b(t_list **head_a, t_list **head_b);
void	push_a(t_list **head_a, t_list **head_b);
void	ft_reverse_rotate(t_list **head, char c);
void	push_create(t_list **head, int num);
char	**ft_split(char const *s, char c);
void	ft_rotate(t_list **head, char c);
void	ft_three_sort(t_list **head);
void	ft_swap(t_list **head, char c);
int		ft_find_max(t_list **head_b);
void	ft_get_index(t_list **head_a);
void	ft_two_sort(t_list **head);
int		ft_list_size(t_list **head);
void	free_split(char **f, int k);
int		ft_strlen(char **s);
void	ft_error_arg(char **str, int ac);

#endif
