/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 11:06:49 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/07 15:47:05 by rpokorny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_simple(t_data *data)
{
	int	node_pos;

	while (get_stack_size(data->a) > 3)
	{
		node_pos = get_node_position(data->a, find_min(data->a));
		bring_node_top(&data->a, node_pos);
		pb(data);
	}
	sort_three(data->a);
	while (get_stack_size(data->b) > 0)
		pa(data);
}
