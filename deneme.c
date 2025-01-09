#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




typedef struct s_zort
{
    int             num;
    struct s_zort    *next;

}    t_list;



static int	ft_negative(char *a1, int *sw)
{
	int	j;
	int	ops;

	j = 0;
	ops = 1;
	while ((a1[j] >= 9 && a1[j] <= 13) || a1[j] == 32)
	{
		j++;
	}
	if (a1[j] == 45 || a1[j] == 43)
	{
		if (a1[j] == 45)
			ops *= -1;
		j++;
	}
	*sw = j;
	return (ops);
}

int	ft_atoi(char *str)
{
	int			i;
	long int	number;
	int			negative;
	char		*s1;

	s1 = (char *)str;
	number = 0;
	negative = ft_negative(s1, &i);
	while (s1[i] >= 48 && s1[i] <= 57)
	{
		number *= 10;
		number += s1[i] - 48;
		i++;
	}
	number *= negative;
	return (number);
}
void ft_del_node(t_list	**head)
{
	t_list *node = *head;
	t_list *prev = NULL;
	while (node->next != NULL)
	{
		if(node->num == 30)
		{
			prev->next = node->next;
			prev = node;
			free(node);
			if (!prev)
				prev = node;
			else
				node = prev->next; 
		}
		else
		{
			prev = node;
			node = node->next;
		}
	}
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

void ft_swap_a(t_list **head)
{
	t_list *node = *head;
	t_list *tmp;

	tmp = node->next;
	node->next = node->next->next;
	tmp->next = node;
	*head = tmp;
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

void ft_reverse_rotate(t_list **head, char c)
{
	t_list *node;
	t_list *last;
	t_list *tmp;

	node = (*head);
	last = (*head);

	while (last->next->next != NULL)
		last = last->next;
	tmp = last->next;
	tmp->next = node;
	last->next = NULL;
	(*head) = tmp;
	if(c == 'a')
		write(1, "rra\n", 4);
	if(c == 'b')
		write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_rrr(t_list **head_a, t_list **head_b)
{
	ft_reverse_rotate(head_a, 'r');
	ft_reverse_rotate(head_b, 'r');
	write(1, "rrr\n", 4);
}

void	ft_rotate(t_list **head, char c)
{
	t_list *first;
	t_list *last;

	first = (*head);
	last = (*head);
	(*head) = first->next;
	while(last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if(c == 'a')
		write(1, "ra\n", 3);
	if(c == 'b')
		write(1, "rb\n", 3);
}

void ft_rotate_rr(t_list **head_a, t_list **head_b)
{
	ft_rotate(head_a, 'r');
	ft_rotate(head_b, 'r');
	write(1, "rr\n", 3);
}

void	ft_swap(t_list **head, char c)
{
	t_list *node = *head;
	t_list *tmp;

	tmp = node->next;
	node->next = node->next->next;
	tmp->next = node;
	(*head) = tmp;
	if(c == 'a')
		write(1, "sa\n", 3);
	if(c == 'b')
		write(1, "sb\n", 3);
}

void	ft_swap_ss(t_list	**head_a, t_list **head_b)
{
	ft_swap(head_a, 's');
	ft_swap(head_b, 's');
	write(1, "ss\n", 3);
}

void	push_create(t_list **head, int num)
{
	t_list *node;
	t_list *new_node;
	node = *head;
	new_node = (t_list *)malloc(sizeof(t_list));
	new_node->num = num;
	new_node->next = node;
	(*head) = new_node;
}

void	push_b(t_list	**head_a, t_list	**head_b)
{
	t_list *tmp;
	push_create(head_b, (*head_a)->num);
	tmp = (*head_a)->next;
	free(*head_a);
	(*head_a) = tmp;
	write(1, "pb\n", 3);
}

void	push_a(t_list **head_a, t_list **head_b)
{
	t_list *tmp;

	push_create(head_a, (*head_b)->num);
	tmp = (*head_b)->next;
	free(*head_b);
	(*head_b) = tmp;
	write(1, "pa\n", 3);
}

int main(int ac, char **av)
{
    t_list *a;
	t_list *b;
	int 	i;
	int		j;
	int 	num;

	a = NULL;
	b = NULL;
	i = 1;
	j = 0;
	num = 0;
	if(ac <= 1)
		return (-1);
	while (av[i] && (j < 4))
	{
		create_node(&a,ft_atoi(av[i]));
		i++;
		j++;
	}
	while (av[i])
	{
		create_node(&b,ft_atoi(av[i]));
		i++;
		j++;
	}
	//ft_swap_a(&a);
	//ft_del_node(&a);
	//ft_print_list(&a);
	//write(1, "\n\n", 2);
	//ft_print_list(&b);
		//push_a(&a,&b);
		ft_reverse_rotate_rrr(&a, &b);
		ft_reverse_rotate(&b, 'b');
		ft_reverse_rotate(&a, 'a');
		ft_rotate(&a, 'a');
		ft_rotate(&b, 'b');
		ft_rotate_rr(&a, &b);
		ft_swap(&a, 'a');
		ft_swap(&b, 'b');
		ft_swap_ss(&a, &b);
		push_a(&a, &b);
		push_b(&a, &b);

		//write(1, "\n\n\n\n......\n", 11);
	ft_print_list(&a);
	write(1, "\n\n", 2);
	ft_print_list(&b);
	return (0);	
}
