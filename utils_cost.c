#include "push_swap.h"
#include <stdlib.h>

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

int	ft_count_cost(t_list	**head_b, t_list	**head_a, int index_a, int	pla_a) // a stacindeki nodun maliyetini hesaplıyor
{
	int		len;
	int		pla_b;
	int		cost;

	len = 0;
	pla_b = 0;
	cost = 0;
	pla_b = ft_place_in_b(head_b, index_a, pla_b, len);
	cost = pla_a + pla_b;
	return(cost);
}

int	ft_place_in_b(t_list	**head_b, int index_a, int	pla_b, int	len)
{
	t_list	*top_b;
	t_list	*closest_smaller_node;

	top_b = (*head_b);
	closest_smaller_node = NULL;
	while(top_b)
	{
		if(index_a > top_b->index)
		{
			if(!closest_smaller_node || (top_b->index > closest_smaller_node->index))
			{
				closest_smaller_node = top_b;
				pla_b = len;
			}
		}
		top_b = top_b->next;
		len++;
	}
	if(!closest_smaller_node)
		pla_b = ft_find_max(head_b);
	return(pla_b);
}

int	ft_find_max(t_list	**head_b)
{
	t_list	*max;
	t_list	*node_b;
	int len;
	int	place;
	
	len = 0;
	place = 0;
	node_b = (*head_b);
	max = (*head_b);
	while (node_b)
	{
		if(node_b->index > max->index)
		{
			max = node_b;
			place = len;
		}
		node_b = node_b->next;
		len++;
	}
	return(place);
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
	if(place >= (size / 2))
		place = size - place;
	return(place); 
}



