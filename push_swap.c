#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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
void	ft_print_list(t_list **head)
{
	t_list *node = *head;
	while(node)
	{
		printf("%d -- %d\n", node->num, node->index);
		node = node->next;
	}

}

int find_smallest(t_list **head_a)
{
	t_list *tmp = (*head_a);
	int small = tmp->num;
	while (tmp)
	{
		if (small > tmp->num)
				small = tmp->num;
		tmp = tmp->next;
	}
	return (small);
}
int	ft_list_size(t_list	**head_a)
{
	t_list	*node;
	int i;

	node = (*head_a);
	while (node)
	{
		i++;
		node = node->next;
	}
	return(i);
}
int is_sorted(t_list **head_a)
{
	t_list *tmp = (*head_a);
	while(tmp->next)
	{
		if(tmp->num > tmp->next->num)
			return(0);
		tmp = tmp->next;
	}
	return(1);
}

int	ft_cost(t_list **head_a, t_list **head_b)
{
	
}

void	ft_sort(t_list	**head_a, t_list	**head_b)
{
	t_list *node;

	node = (*head_a);
	push_b(head_a, head_b);
	push_b(head_a, head_b);
	if((*head_b)->index < (*head_b)->next->index)
		ft_swap(head_b, 'b');
	while ((*head_a))
	{
		
	}
	
}

void	ft_get_index(t_list **head_a)
{
	t_list	*node;
	t_list	*current;
	t_list	*tmp;
	int		i;

	i = 0;
	node = (*head_a);
	current = (*head_a);
	while (node)
	{
		i++;
		current = (*head_a);
		while (current->index != 0)
			current = current->next;
		tmp = current;
		while (current)
		{
			if ((tmp->num > current->num) && (current->index == 0))
				tmp = current;
			current = current->next;
		}
		tmp->index = i;
		node = node->next;
	}
}

int main(int ac, char **av)
{
	t_list	*a = NULL;
	t_list	*b = NULL;
	int	i;

	i = 1;
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
	ft_get_index(&a);
	ft_print_list(&a);
	//ft_bubble(&a, &b);
	//write(1, "\n\n\n", 3);
	//ft_print_list(&a);
}
