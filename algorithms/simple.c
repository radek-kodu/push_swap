#include "../push_swap.h"

void	sort_simple(t_node **a, t_node **b)
{
	int	node_pos;
	
	while (get_stack_size(*a) > 3)
	{
		node_pos = get_node_position(*a, find_min(*a));
		bring_node_top(a, node_pos);
		pb(a,b);
	}
	sort_three(a);
	while (get_stack_size(*b) > 0)
		pa(a,b);
}

