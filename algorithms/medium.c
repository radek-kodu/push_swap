/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:17:18 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/12 11:18:54 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	chunk_sizer(int argc)
{
	int	devider;
	int	chunk_size;

	if (argc >= 6 && argc <= 100)
		devider = 6;
	else
		devider = 10;
	chunk_size = (argc + devider - 1) / devider;
	return (chunk_size);
}

static void	chunk_mover(int *start, int *top, int chunk_size, int size)
{
	*start = *top;
	*top = *top + chunk_size;
	if (*top > size)
		*top = size;
}

static void	push_chunk(t_data *data, int start, int top)
{
	int	i;

	i = 0;
	while (data->a && i < top - start)
	{
		if (data->a->index >= start && data->a->index < top)
		{
			pb(data);
			i++;
		}
		else
			ra(data);
	}
}

static int	get_pos(t_node *stack, int size)
{
	t_node	*largest_node;
	int		node_pos;

	largest_node = stack;
	while (largest_node && largest_node-> index != size -1)
		largest_node = largest_node->next;
	node_pos = get_node_position(stack, largest_node);
	return (node_pos);
}

void	sort_medium(t_data *data)
{
	int		chunk_size;
	int		start;
	int		top;
	int		size;
	int		node_pos;

	size = data->size;
	start = 0;
	chunk_size = chunk_sizer(size);
	top = chunk_size;
	while (start < size)
	{
		push_chunk(data, start, top);
		chunk_mover(&start, &top, chunk_size, size);
	}
	while (size > 0)
	{
		node_pos = get_pos(data->b, size);
		if (node_pos == -1)
			return ;
		bring_node_top(data, node_pos, 'b');
		pa(data);
		size--;
	}
}

		// largest_node = data->b;
		// while (largest_node && largest_node-> index != size -1)
		// 	largest_node = largest_node->next;
		// node_pos = get_node_position(data->b, largest_node);