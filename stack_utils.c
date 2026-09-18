/*

Helper functions for building, inspecting, and cleaning up the linked-list stack. These may include:

1. new_node: creates a new stack || t_node	*new_node(int value);
2. stack_add_back: adds a new node at the end || void stack_add_back(t_node **a, t_node *new);
3. stack_size: returns the number of nodes || int	stack_size(t_node *a);
4. is_sorted: checks if the stack is sorted || int     is_sorted(t_node *a);
5. last_node: returns a pointer to the last node (see rotate.c)
6. free_stack: destroys the stack || void    free_stack(t_node **a);

*/

#include "push_swap.h"

int	is_sorted(t_node *a)
{
	// 1 is sorted, 0 is not sorted
	if (!a)
		return (1);
	while (a->next != NULL)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

t_node	*lastnode(t_node *a)
{
	if (!a)
		return (NULL);
	while (a->next != NULL)
		a = a->next;
	return (a);
}