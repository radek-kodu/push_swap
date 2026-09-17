#include "../push_swap.h"

void	push(t_node **dest, t_node **src)
{
	t_node	*temp;
	// if src is empty
	if (*src == NULL)
		return ;
	// Save top node of src
	temp = *src;
	// Make src point to next node
	*src = (*src)->next;
	// Add saved first node to front of dest
	temp->next = *dest;
	// Make dest point to saved node
	*dest = temp;
}

void	pa(t_node **a, t_node **b)
{
	push(a,b);
}

void	pb(t_node **a, t_node **b)
{
	push(b,a);
}
