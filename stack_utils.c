/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:44:54 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/09 17:49:59 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Helper functions for building, inspecting, 
and cleaning up the linked-list stack. 

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

int	get_node_position(t_node *a, t_node *node)
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

int	get_stack_size(t_data *data)
{
	int	stack_size;

	stack_size = 0;
	if (!data->a)
		return (stack_size);
	while (data->a)
	{
		stack_size++;
		data->a = data->a->next;
	}
	return (stack_size);
}
