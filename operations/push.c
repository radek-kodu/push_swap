/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:27:55 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/07 12:55:58 by rpokorny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_node **dest, t_node **src)
{
	t_node	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	pa(t_data *data)
{
	data->bench.pa++;
	write (1, "pa\n", 3);
	push (&data->a, &data->b);
}

void	pb(t_data *data)
{
	data->bench.pb++;
	write (1, "pb\n", 3);
	push (&data->b, &data->a);
}
