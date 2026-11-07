/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:33:59 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/07 14:32:21 by rpokorny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Specialized handling for n<= 5
*/
#include "../push_swap.h"

static void	bring_min_top(t_data *data, int min_pos);

// For sorting 2 nodes
void	sort_two(t_data *data)
{
	if (!is_sorted(data->a))
		sa(data);
}

// For sorting 3 nodes
void	sort_three(t_data *data)
{
	// Check if already sorted
	if (!is_sorted(data->a))
	{
		// Largest at the bottom: 213 -> sa
		if (data->a->next->next->value > data->a->next->value &&
			data->a->next->next->value > data->a->value)
				sa(data);
		// Largest at the middle (213, 132)
		else if (data->a->next->value > data->a->value &&
			data->a->next->value > data->a->next->next->value)
		{
			// 231 -> rra (123)
			// 132 -> rra (213), sa (123)
			rra(data);
			if (!is_sorted(data->a))
				sa(data);
		}
		// Largest at the top (312, 321)
		else
		{
			// 312 -> ra
			// 321 -> ra(213), sa(123)
			ra(data);
			if (!is_sorted(data->a))
				sa(data);
		}
	}
}

// For sorting 4-5 nodes only
void    sort_small(t_data *data)
{
	int		min_pos;
	int		orig_stack_size;

	if (!data)
		return ;
	orig_stack_size = get_stack_size(data->a);
	while (get_stack_size(data->a) > 3)
	{
		//get node_position of min
		min_pos = get_node_position(data->a, find_min(data->a));
		// bring_min_top
		bring_min_top(data, min_pos);
		// push to b
		pb(data);
	}
	// sort_three a
	sort_three(data);
	// push back nodes from b to a
	while (get_stack_size(data->a) < orig_stack_size)
		pa(data);
}

static void	bring_min_top(t_data *data, int min_pos)
{
	if (!data->a || min_pos == 0)
		return ;
	else if (min_pos == 1)
		sa(data);
	else if (min_pos == 2)
	{
		ra(data);
		ra(data);
	}
	else if (min_pos == 3)
	{
		rra(data);
		rra(data);
	}
	else if (min_pos == 4)
		rra(data);
	else
		return ;
}
