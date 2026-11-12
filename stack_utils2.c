/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:48:52 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/12 11:49:13 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Helper functions for building, inspecting, 
and cleaning up the linked-list stack. 

* bring_node_top: pushes a node to the top of the stack
* is_duplicate: checks if int value already exists in the stack
* stack_add_back: adds a new node at the bottom of the stack

*/

#include "push_swap.h"

static void	rotate_stack(t_data *data, char stack);
static void	reverse_rotate_stack(t_data *data, char stack);

void	bring_node_top(t_data *data, int node_pos, char stack)
{
	int	middle_pos;
	int	stack_size;

	if (stack == 'a')
		stack_size = get_stack_size(data->a);
	else if (stack == 'b')
		stack_size = get_stack_size(data->b);
	else
		return ;
	middle_pos = stack_size / 2;
	while (node_pos > 0 && node_pos <= middle_pos)
	{
		rotate_stack(data, stack);
		node_pos--;
	}
	while (node_pos > middle_pos && node_pos < stack_size)
	{
		reverse_rotate_stack(data, stack);
		node_pos++;
	}
}

static void	rotate_stack(t_data *data, char stack)
{
	if (stack == 'a')
		ra(data);
	else
		rb(data);
}

static void	reverse_rotate_stack(t_data *data, char stack)
{
	if (stack == 'a')
		rra(data);
	else
		rrb(data);
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
