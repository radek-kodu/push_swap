#include "../push_swap.h"

void	swap_toptwo(t_node **c)
{
    int temp_value;
    int temp_index;

    /* if 0 or 1 nodes, return*/
    if (*c == NULL)
        return ;
    if ((*c)->next == NULL)
        return ;
    /*switch values*/
    temp_value = (*c)->value;
    (*c)->value = (*c)->next->value;
    (*c)->next->value = temp_value;
    /*also switch index*/
    temp_index = (*c)->index;
    (*c)->index = (*c)->next->index;
    (*c)->next->index = temp_index;
}

void	sa(t_node **a)
{
    swap_toptwo(a);
}

void	sb(t_node **b)
{
    swap_toptwo(b);
}

void	ss(t_node **a, t_node **b)
{
    swap_toptwo(a);
    swap_toptwo(b);
}