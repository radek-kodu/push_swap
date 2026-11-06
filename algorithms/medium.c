/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:17:18 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/06 20:43:14 by rpokorny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	push_chunk(t_node **a, t_node **b, int start, int top)
{
	int	i;

	i = 0;
	while (*a && i < top - start)
	{
		if ((*a)->index >= start && (*a)->index < top)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

void	sort_medium(t_node **a, t_node **b, int argc)
{
	int	chunk_size;
	int	start;
	int	top;
	int	size;

	size = argc - 1;
	start = 0;
	chunk_size = chunk_sizer(size);
	top = chunk_size;
	while (start < size)
	{
		push_chunk(a, b, start, top);
		chunk_mover(&start, &top, chunk_size, size);
	}
	while (size - 1 >= 0)
	{
		while (*b && size - 1 != (*b)->index)
			rb(b);
		pa(a, b);
		size--;
	}
}
