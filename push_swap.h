
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
    int             num;
	int				index;
    struct s_list    *next;

} t_list;

	void	ft_swap(t_list **head, char c);
	void	ft_swap_ss(t_list	**head_a, t_list **head_b);

	void	push_b(t_list **head_a, t_list **head_b);
	void	push_a(t_list **head_a, t_list **head_b);
	void	push_create(t_list **head, int num);

	void	ft_reverse_rotate_rrr(t_list **head_a, t_list **head_b);
	void	ft_rotate_rr(t_list **head_a, t_list **head_b);
	void	ft_reverse_rotate(t_list **head, char c);
	void	ft_rotate(t_list **head, char c);

	t_list	*ft_less_cost(t_list	**head_a, t_list	**head_b);
	int		ft_count_cost(t_list	**head_b, t_list	**head_a, int index_a, int	pla_a);
	int		ft_place_in_b(t_list	**head_b, int index_a, int	pla_b, int	len);
	int		ft_find_max(t_list	**head_b);
	int		ft_optimize_move(t_list	**head, int	place);
	void	ft_get_index(t_list **head_a);
	void	ft_last_sort(t_list	**head_a, t_list	**head_b);
	void	ft_sort_in_b(t_list	**head_a, t_list	**head_b);
	void	ft_push_min(t_list	**head_a, t_list	**head_b, int	min_index);
	void	ft_three_sort(t_list	**head);
	void	ft_two_sort(t_list	**head);
	int		ft_list_size(t_list	**head);
	void	ft_move_big_node(t_list	**head_b, int	step);
	void	ft_make_head_in_b(t_list	**head_b, int index_a);
	void	ft_move(t_list	**head, int	cost_size, char op, char	stack);
	int		ft_atoi(char *str);




#endif
