#include "../push_swap.h"

void	sa(t_node **a)
{
    int temp_value;
    int temp_index;

    /* if 0 or 1 nodes, return*/
    if (*a == NULL)
        return ;
    if ((*a)->next == NULL)
        return ;
    /*switch values*/
    temp_value = (*a)->value;
    (*a)->value = (*a)->next->value;
    (*a)->next->value = temp_value;

    /*also switch index*/
    temp_index = (*a)->index;
    (*a)->index = (*a)->next->index;
    (*a)->next->index = temp_index;
}

void	sb(t_node **b);
void	ss(t_node **a, t_node **b);