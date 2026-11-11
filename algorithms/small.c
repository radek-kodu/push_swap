/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:33:59 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/11 12:08:09 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Specialized handling for n<= 5
*/
#include "../push_swap.h"

// static void	bring_min_top(t_data *data, int min_pos);

// For sorting 2 nodes
void	sort_two(t_data *data)
{
	if (!is_sorted(data->a))
		sa(data);
}

// For sorting 3 nodes
void	sort_three(t_data *data)
{
	if (!is_sorted(data->a))
	{
		if (data->a->next->next->value > data->a->next->value
			&& data->a->next->next->value > data->a->value)
			sa(data);
		else if (data->a->next->value > data->a->value
			&& data->a->next->value > data->a->next->next->value)
		{
			rra(data);
			if (!is_sorted(data->a))
				sa(data);
		}
		else
		{
			ra(data);
			if (!is_sorted(data->a))
				sa(data);
		}
	}
}

// For sorting 4-5 nodes only
void	sort_small(t_data *data)
{
	int		min_pos;
	int		orig_stack_size;

	if (!data)
		return ;
	orig_stack_size = get_stack_size(data->a);
	if (get_stack_size(data->a) == 2)
		return(sort_two(data));
	while (get_stack_size(data->a) > 3)
	{
		min_pos = get_node_position(data->a, find_min(data->a));
		bring_node_top(data, min_pos, 'a');
		pb(data);
	}
	sort_three(data);
	while (get_stack_size(data->a) < orig_stack_size)
		pa(data);
}

/*
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
*/