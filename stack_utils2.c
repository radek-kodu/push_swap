/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:48:52 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/11 14:12:23 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    rotate_stack(t_data *data, char stack);
static void    reverse_rotate_stack(t_data *data, char stack);

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

static void    rotate_stack(t_data *data, char stack)
{
    if (stack == 'a')
        ra(data);
    else
        rb(data);
}

static void    reverse_rotate_stack(t_data *data, char stack)
{
    if (stack == 'a')
        rra(data);
    else
        rrb(data);
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

// void	stack_add_back(t_node **stack, t_node *new)
// {
// 	t_node	*current;

// 	if (*stack == NULL)
// 	{
// 		*stack = new;
// 		return ;
// 	}
// 	current = *stack;
// 	while (current->next)
// 		current = current->next;
// 	current->next = new;
// }

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
