/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:28:04 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/07 13:00:05 by rpokorny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	t_node	*secondlast(t_node *x)
{
	if (!x || !x->next)
		return (NULL);
	while (x->next->next != NULL)
		x = x->next;
	return (x);
}

/* Shift down all elements of the stack by one.
The last element becomes the first one.*/
static void	reverse_rotate(t_node **x)
{
	t_node	*temp;
	t_node	*newlast;

	if (*x == NULL || (*x)->next == NULL)
		return ;
	temp = lastnode(*x);
	newlast = secondlast(*x);
	newlast->next = NULL;
	temp->next = *x;
	*x = temp;
}

void	rra(t_data *data)
{
	data->bench.rra++;
	write (1, "rra\n", 4);
	reverse_rotate(&data->a);
}

void	rrb(t_data *data)
{
	data->bench.rrb++;
	write (1, "rrb\n", 4);
	reverse_rotate(&data->b);
}

void	rrr(t_data *data)
{
	data->bench.rrr++;
	write (1, "rrr\n", 4);
	reverse_rotate(&data->a);
	reverse_rotate(&data->b);
}
