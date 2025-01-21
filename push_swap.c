#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

void create_node(t_list **head, int data) // yeni bir node oluşturup sona ekler
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    new_node->num = data;
	new_node->index = 0;
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

void	ft_stack_processor(t_list	**stack_a, t_list	**stack_b)
{
	int node_size;

	node_size = ft_list_size(stack_a);;
	if (node_size == 2)
		ft_two_sort(stack_a);
	else if (node_size == 3)
		ft_three_sort(stack_a);
	else if (node_size > 3)
	{
		ft_sort_in_b(stack_a, stack_b);
		ft_three_sort(stack_a);
		ft_last_sort(stack_a, stack_b);
	}
}

int main(int ac, char **av)
{
	t_list	*a = NULL;
	t_list	*b = NULL;
	int	i;

	i = 1;
	if (ac < 2)
		return (0);
	if(ac == 2)
	{
		av = ft_split();
	}
	while (av[i])
	{
		create_node(&a, ft_atoi(av[i]));
		i++;
	}
	ft_get_index(&a);
	ft_stack_processor(&a, &b);
}
