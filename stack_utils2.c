/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:48:52 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/09 18:36:27 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_node_top(t_data *data, int node_pos)
{
	int	middle_pos;
	int	stack_size;

	stack_size = get_stack_size(data->a);
	middle_pos = stack_size / 2;
	if (node_pos <= middle_pos)
	{
		while (node_pos > 0)
		{
			ra(data);
			node_pos--;
		}
	}
	else
	{
		while (node_pos != stack_size)
		{
			rra(data);
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
	t_node	*current;

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

t_node	*free_stack(t_node *stack)
{
	t_node	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	return (NULL);
}
