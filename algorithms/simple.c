/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 11:06:49 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/12 12:21:31 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_simple(t_data *data)
{
	int	node_pos;

	while (get_stack_size(data->a) > 3)
	{
		node_pos = get_node_position(data->a, find_min(data->a));
		bring_node_top(data, node_pos, 'a');
		pb(data);
	}
	sort_three(data);
	while (get_stack_size(data->b) > 0)
		pa(data);
}
