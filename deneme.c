#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




typedef struct s_zort
{
    int             num;
    struct s_zort    *next_a;
    struct s_zort    *next_b;

}    t_zort;



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
void ft_del_node(t_zort	**head)
{
	t_zort *node = *head;
	t_zort *prev = NULL;
	while (node->next_a != NULL)
	{
		if(node->num == 30)
		{
			prev->next_a = node->next_a;
			prev = node;
			free(node);
			if (!prev)
				prev = node;
			else
				node = prev->next_a; 
		}
		else
		{
			prev = node;
			node = node->next_a;
		}
	}
}

void create_node(t_zort **head, int data)
{
    t_zort *new_node = (t_zort *)malloc(sizeof(t_zort));
    new_node->num = data;
    new_node->next_a = NULL;

    if (*head == NULL) {
        *head = new_node;
    } 
    else 
    {
        t_zort *current = *head;
        while (current->next_a != NULL)
            current = current->next_a;
       current->next_a = new_node;
    }
}

void ft_swap_a(t_zort **head)
{
	t_zort *node = *head;
	t_zort *tmp;

	tmp = node->next_a;
	node->next_a = node->next_a->next_a;
	tmp->next_a = node;
	*head = tmp;
}

void	ft_print_list(t_zort **head)
{

	t_zort *node = *head;
	while(node)
	{
	printf("%d\n", node->num);
	node = node->next_a;
	}

}
int main(int ac, char **av)
{
    t_zort *a;
	int 	i;
	int 	num;
    
    a = NULL;
	i = 1;
	num = 0;
	if(ac <= 1)
		return (-1);
	while (av[i])
	{
		create_node(&a,ft_atoi(av[i]));
		i++;
	}
	//ft_swap_a(&a);
	ft_del_node(&a);
	ft_print_list(&a);
	return (0);

	
}
