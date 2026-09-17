#include "../push_swap.h"

static	t_node *lastnode(t_node *x)
{
	if (!x)
		return (NULL);
	while (x->next != NULL)
		x = x->next;
	return (x);
}

void    rotate(t_node **x)
{
	t_node	*temp;
	t_node	*last;
	// handle if x is null
	if (*x == NULL)
		return ;
	// handle if x-> next is null (just 1 node)
	if ((*x)->next == NULL)
		return ;
	// save first node pointed by x to temp
	temp = *x;
	// move x pointer to 2nd node
	*x = (*x)->next;
	// detach first node of temp
	temp->next = NULL;
	// attach temp to end of x
	last = lastnode(*x);
	last->next = temp;
}

void	ra(t_node **a)
{
	rotate(a);
}

void	rb(t_node **b)
{
	rotate(b);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
}