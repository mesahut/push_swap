#include <unistd.h>
#include "push_swap.h"

int	ft_atoi(char *str)
{
	int			i;
	long int	number;
	int			negative;

	number = 0;
	i = 0;
	negative = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			negative *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		number *= 10;
		number += str[i] - 48;
		i++;
	}
	number *= negative;
	return (number);
}
void create_node(t_list **head, int data)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    new_node->num = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } 
    else 
    {
        t_list *current = *head;
        while (current->next != NULL)
            current = current->next;
       current->next = new_node;
    }
}
void	ft_print_list(t_list **head)
{
	t_list *node = *head;
	while(node)
	{
	printf("%d\n", node->num);
	node = node->next;
	}

}

void	ft_small(t_list	**head_a, t_list **head_b)
{
	t_list	*last_a = *head_a;
	t_list	*last_b = *head_b;
	t_list	*first_a = *head_a;
	t_list	*first_b = *head_b;
	int i;
	int j;

	i = 0;
	j = 0;
	while(last_a->next)
		last_a = last_a->next;
	while(last_b->next)
		last_b = last_b->next;
	while (first_a)
	{
		if(last_a->num > first_a->num)
			i += 1;
		first_a = first_a->next;
	}
	while (first_b)
	{
		if(last_b->num > first_b->num)
			j += 1;
		first_b = first_b->next;
	}
	if((i == 0) && (j == 0))
		ft_reverse_rotate_rrr(&head_a, &head_b);
	else if(i == 0)
		ft_reverse_rotate(&head_a, 'a');
	else if(j == 0)
		ft_reverse_rotate(&head_b, 'b');
}

void	ft_change(t_list **head_a, t_list **head_b)

void	ft_sort(t_list **head_a, t_list **head_b)
{
	t_list	*first_a = *head_a;
	t_list	*first_b = *head_b;


	ft_small(&head_a, &head_b);
	ft_change(&head_a, )
}

int main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int	i;

	i = 0;
	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (av[i])
	{
		create_node(&a, ft_atoi(av[i]));
		i++;
	}
	ft_sort(&a, &b);
	

}
