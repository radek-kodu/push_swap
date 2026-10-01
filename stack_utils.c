/*

Helper functions for building, inspecting, and cleaning up the linked-list stack. 

* is_sorted: checks if the stack is sorted 
* last_node: returns a pointer to the last node
* find_min: returns a pointer to the node with the smallest value
* get_node_position: returns an int indicating the position of a node
* get_stack_size: returns the number of nodes
* bring_node_top: pushes a node to the top of the stack
* new_node: creates a new stack with initialized values
* is_duplicate: checks if int value already exists in the stack
* stack_add_back: adds a new node at the bottom of the stack

----------
Other possible functions:
free_stack: destroys the stack || void    free_stack(t_node **a);

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

t_node	*find_min(t_node *a)
{
	t_node	*min;

	if (!a)
		return (NULL);
	min = a;
	while (a)
	{
		if (a->value < min->value)
			min = a;
		a = a->next;
	}
	return (min);
}

int get_node_position(t_node *a, t_node *node)
{
	int	position;

	if (!a || !node)
		return (-1);
	position = 0;
	while (a)
	{
		if (a == node)
			return (position);
		a = a->next;
		position++;
	}
	return (-1);
}

int	get_stack_size(t_node *a)
{
	int	stack_size;

	stack_size = 0;
	if (!a)
		return (stack_size);
	while (a)
	{
		stack_size++;
		a = a->next;
	}
	return (stack_size);
}

void	bring_node_top(t_node **a, int node_pos)
{
	int	middle_pos;
	int	stack_size;

	stack_size = get_stack_size(*a);
	middle_pos = stack_size/2;
	// if node_pos < middle_pos (push up until node_pos == 0)
	if (node_pos <= middle_pos)
	{
		while (node_pos > 0)
		{
			ra(a);
			node_pos--;
		}
	} 
	// if node_pos > middle_pos (push down until node_pos wraps around to 0)
	else
	{
		while (node_pos != stack_size)
		{
			rra(a);
			node_pos++;
		}
	}
}

t_node	*new_node(int value)
{
	t_node	*node;
	
	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

int	is_duplicate(int nbr, t_node *stack)
{
	while (stack)
	{
		if (nbr == stack->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	stack_add_back(t_node **stack, t_node *new)
{
	t_node *current;

	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new;
}

void	free_stack(t_node *stack)
{

}
