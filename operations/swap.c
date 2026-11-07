/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:28:20 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/07 12:59:50 by rpokorny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_toptwo(t_node **c)
{
	t_node	*temp_ptr;

	if (*c == NULL || (*c)->next == NULL)
		return ;
	temp_ptr = (*c)->next;
	(*c)->next = (*c)->next->next;
	temp_ptr->next = *c;
	*c = temp_ptr;
}

// static void	swap_toptwo(t_node **c)
// {
//     int temp_value;
//     int temp_index;

//     /* if 0 or 1 nodes, return*/
//     if (*c == NULL)
//         return ;
//     if ((*c)->next == NULL)
//         return ;
//     /*switch values*/
//     temp_value = (*c)->value;
//     (*c)->value = (*c)->next->value;
//     (*c)->next->value = temp_value;
//     /*also switch index*/
//     temp_index = (*c)->index;
//     (*c)->index = (*c)->next->index;
//     (*c)->next->index = temp_index;
// }

void	sa(t_data *data)
{
	data->bench.sa++;
	write (1, "sa\n", 3);
	swap_toptwo(&data->a);
}

void	sb(t_data *data)
{
	data->bench.sb++;
	write (1, "sb\n", 3);
	swap_toptwo(&data->b);
}

void	ss(t_data *data)
{
	data->bench.ss++;
	write (1, "ss\n", 3);
	swap_toptwo(&data->a);
	swap_toptwo(&data->b);
}
