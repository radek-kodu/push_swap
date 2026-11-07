/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:28:11 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/07 12:58:42 by rpokorny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_node **x)
{
	t_node	*temp;
	t_node	*last;

	if (*x == NULL)
		return ;
	if ((*x)->next == NULL)
		return ;
	temp = *x;
	*x = (*x)->next;
	temp->next = NULL;
	last = lastnode(*x);
	last->next = temp;
}

void	ra(t_data *data)
{
	data->bench.ra++;
	write (1, "ra\n", 3);
	rotate (&data->a);
}

void	rb(t_data *data)
{
	data->bench.rb++;
	write (1, "rb\n", 3);
	rotate (&data->b);
}

void	rr(t_data *data)
{
	data->bench.rr++;
	write (1, "rr\n", 3);
	rotate (&data->a);
	rotate (&data->b);
}
