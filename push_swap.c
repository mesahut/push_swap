#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int	ft_atoi(char *str) // bildiğin atoi
{
	int			i;
	long int	number;
	int			negative;

	i = 0;
	number = 0;
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
	return (number * negative);
}
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
void	ft_print_list(t_list **head) // listenin bütün nodlarını indeksleriyle baraber yazırır
{
	t_list *node = *head;
	while(node)
	{
		printf("%d -- %d\n", node->num, node->index);
		node = node->next;
	}

}

int find_smallest(t_list **head_a) // (şu an kullanmıyorum)
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
int	ft_list_size(t_list	**head) // (şu an kullanmıyorum) listenin sizeını verir
{
	t_list	*node;
	int i;

	node = (*head);
	while (node)
	{
		i++;
		node = node->next;
	}
	return(i);
}
int is_sorted(t_list **head_a) // (şu an kullanmıyorum) liste sortlanmışmı kontrol eder
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

int ft_optimize_move(t_list	**head, int	place) // eğer en optimize node stacin yarısından daha alttaysa ra yerine rra yapıyor
{
	t_list	*node;
	int size;

	node = (*head);
	while (node)
	{
		size++;
		node = node->next;
	}
	if(place > (size / 2))
		place = size - place;
	return(place); 
}

int	ft_count_cost(t_list	**head_b, t_list	**head_a, int index_a, int	pla_a) // a stacindeki nodun maliyetini hesaplıyor
{
	t_list	*closest_smaller_node;
	t_list	*top_b;
	int		len;
	int		pla_b;
	int		cost;

	len = 0;
	pla_b = 0;
	cost = 0;
	top_b = (*head_b);
	closest_smaller_node = NULL;
	while(top_b)
	{
		if(index_a > top_b->index)
		{
			if(!closest_smaller_node)
			{
				closest_smaller_node = top_b;
				pla_b = len;
			}
			else if(top_b->index > closest_smaller_node->index)
			{
				closest_smaller_node = top_b;
				pla_b = len;
			}
		}
		top_b = top_b->next;
		len++;
	}
	pla_a = ft_optimize_move(head_a, pla_a);
	pla_b = ft_optimize_move(head_b, pla_b);
	cost = pla_a + pla_b;
	return(cost);
}

t_list	*ft_less_cost(t_list	**head_a, t_list	**head_b) // en düşük maliyetli nodu döndürüyor
{
	t_list	*cost_node;
	t_list	*less;
	int		cost;
	int		newcost;
	int		pla_a;

	pla_a = 1;
	cost_node = (*head_a);
	cost = ft_count_cost(head_b, head_a, cost_node->index, 0);
	less = cost_node;
	cost_node = cost_node->next;
	while (cost_node)
	{
		newcost = ft_count_cost(head_b, head_a, cost_node->index, pla_a);
		if(newcost < cost)
		{
			less = cost_node;
			cost = newcost;
		}
		pla_a++;
		cost_node = cost_node->next;
	}
	return(less);
}

void	ft_two_push(t_list	**head_a, t_list	**head_b) // a stacindeki ilk iki nodu b stackine pushlar ve sortlar
{
	push_b(head_a, head_b);
	push_b(head_a, head_b);
	if((*head_b)->index < (*head_b)->next->index)
		ft_swap(head_b, 'b');
}

void	ft_sort(t_list	**head_a, t_list	**head_b) // ana sıralamayla ilgili fonksiyon
{
	t_list	*node;
	t_list	*min_cost;

	node = (*head_a);
	ft_two_push(head_a, head_b);
	min_cost = ft_less_cost(head_a, head_b);
}

void	ft_get_index(t_list **head_a) // nodeların sıralandıktan sonra olması gereken yerlerindeki indeksleri indeks değişkenine yazar
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
	ft_sort(&a, &b);
	ft_print_list(&a);
}
