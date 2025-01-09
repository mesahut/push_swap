
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



#endif


