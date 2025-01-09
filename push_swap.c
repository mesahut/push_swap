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

void	ft_small_push(t_list	**a, t_list	**b, int	count, int	size)
{
	int	select;
	if((size/2) >= count)
		select = 1;
	if((size/2) < count)
		select = 0;
	while (count >= 0)
	{
		if(select == 0)
			ft_reverse_rotate(a, 'a');
		if(select == 1)
			ft_rotate(a, 'a');
		count--;
	}
	push_b(a, b);
}

void	ft_bubble(t_list	**head_a, t_list	**head_b)
{
	t_list	*tmp;
	t_list	*node;
	int		count;
	int		size;

	node = *head_a;
	tmp = node;
	size = 0;
	count = 0;
	while ((*head_a)->next != NULL)
	{
		while (node)
		{
			if(tmp->num > node->num)
			{
				tmp = node;
				count++;
			}
			node = node->next;
			size++;
		}
		ft_small_push(head_a, head_b, count, size);
	}
/* 	while ((*head_b) == NULL)
		push_a(head_a, head_b); */
}

int main(int ac, char **av)
{
	t_list	*a = NULL;
	t_list	*b = NULL;
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
	//ft_print_list(&a);
	ft_bubble(&a, &b);
	//write(1, "\n\n\n", 3);
	//ft_print_list(&a);
}
