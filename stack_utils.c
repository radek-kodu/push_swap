/*

Helper functions for building, inspecting, and cleaning up the linked-list stack
These may include:
1. new_node: creates a new stack
2. stack_size: returns the number of nodes
3. is_sorted: checks if the stack is sorted || int     is_sorted(t_node *a);
4. last_node: returns a pointer to the last node (see rotate.c)
5. free_stack: destroys the stack || void    free_stack(t_node **a);

*/
#include "push_swap.h"

t_node	*lastnode(t_node *a)
{
	if (!a)
		return (NULL);
	while (a->next != NULL)
		a = a->next;
	return (a);
}