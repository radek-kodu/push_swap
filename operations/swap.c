/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:28:20 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/11 09:09:49 by camille          ###   ########.fr       */
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
