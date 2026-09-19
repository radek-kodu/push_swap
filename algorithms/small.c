/*
Specialized handling for n<= 5
*/
#include "../push_swap.h"

static void	bring_min_top(t_node **a, int min_pos);

// For sorting 2 nodes
void	sort_two(t_node **a)
{
	if (!is_sorted(*a))
		sa(a);
}

// For sorting 3 nodes
void	sort_three(t_node **a)
{
	// Check if already sorted
	if (!is_sorted(*a))
	{
		// Largest at the bottom: 213 -> sa
		if ((*a)->next->next->value > (*a)->next->value &&
			(*a)->next->next->value > (*a)->value)
				sa(a);
		// Largest at the middle (213, 132)
		else if ((*a)->next->value > (*a)->value &&
			(*a)->next->value > (*a)->next->next->value)
		{
			// 231 -> rra (123)
			// 132 -> rra (213), sa (123)
			rra(a);
			if (!is_sorted(*a))
				sa(a);
		}
		// Largest at the top (312, 321)
		else
		{
			// 312 -> ra
			// 321 -> ra(213), sa(123)
			ra(a);
			if (!is_sorted(*a))
				sa(a);
		}
	}
}

// For sorting 4-5 nodes only
void    sort_small(t_node **a, t_node **b)
{
	int		min_pos;
	int		orig_stack_size;

	if (!a || !b)
		return ;
	orig_stack_size = get_stack_size(*a);
	while (get_stack_size(*a) > 3)
	{
		//get node_position of min
		min_pos = get_node_position(*a, find_min(*a));
		// bring_min_top
		bring_min_top(a, min_pos);
		// push to b
		pb(a,b);
	}
	// sort_three a
	sort_three(a);
	// push back nodes from b to a
	while (get_stack_size(*a) < orig_stack_size)
		pa(a,b);
}

static void	bring_min_top(t_node **a, int min_pos)
{
	if (!a || min_pos == 0)
		return ;
	else if (min_pos == 1)
		sa(a);
	else if (min_pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_pos == 3)
	{
		rra(a);
		rra(a);
	}
	else if (min_pos == 4)
		rra(a);
	else
		return ;
}