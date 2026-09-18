/*
Specialized handling for n<= 5
*/
#include "../push_swap.h"

void	sort_two(t_node **a)
{
	if (is_sorted(*a) != 0)
		sa(a);
}

void	sort_three(t_node **a)
{
	// Check if already sorted
	if (is_sorted(*a) != 0)
	{
		// Largest at the bottom: 213 -> sa
		if ((*a)->next->next->value > (*a)->next->value &&
			(*a)->next->next->value > (*a)->value)
				sa(a);
		// Largest at the middle
		if ((*a)->next->value > (*a)->value &&
			(*a)->next->value > (*a)->next->next->value)
		{
			// 231 -> rra
			if ((*a)->value > (*a)->next->next->value)
				rra(a);
			// 132 -> sa, ra
			if ((*a)->value < (*a)->next->next->value)
			{
				sa(a);
				ra(a);
			}
		}
		// Largest at the top
		if ((*a)->value >  (*a)->next->value &&
			(*a)->value > (*a)->next->next->value)
		{
			// 312 -> ra
			if ((*a)->next->value < (*a)->next->next->value)
				ra(a);
			// 321 -> sa, rra
			if ((*a)->next->value > (*a)->next->next->value)
			{
				sa(a);
				rra(a);
			}
		}
	}
}

void    sort_four(t_node **a, t_node **b);
void    sort_five(t_node **a, t_node **b);