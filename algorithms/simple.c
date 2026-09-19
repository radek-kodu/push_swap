#include "../push_swap.h"

void	sort_simple(t_node **a, t_node **b)
{
	// do this while get_stack_size(*a) > 3
		// find_min
		// bring_node_top
		// pb
	// sort_three
	// do this while get_stack_size(*b) > 0
		// pa
}

void	bring_node_top(t_node **a, int node_pos)
{
	// get middle position (stack size/2)
	// get_node_position
	// bring node top
	// if node_pos is from 1 to middle_pos (push up until node_pos == 0)
		// even(6), middle_pos (3) -> max 3 (max middle_pos)
		// odd (5), middle (2) -> max 2 (max middle_pos)
	// if node_pos > middle_pos (push down until node_pos == 0)
		// even(6), node_pos (4) -> max 3 (max middle pos)
		// odd (5), node_pos (3) -> max 2 (max middle - 1)
}