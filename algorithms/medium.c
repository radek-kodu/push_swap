/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:17:18 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/04 19:07:51 by rpokorny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_sizer(int argc)
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

int	*chunk_mover(int chunk[3], int chunk_size, int argc)
{
	if (chunk[0] == 0)
	{
		chunk[1] = chunk_size / 2;
		chunk[2] = chunk_size;
		return (chunk);
	}
	chunk[0] += chunk_size;
	chunk[2] += chunk_size;
	if (chunk[2] > argc)
		chunk[2] = argc;
	chunk[1] = (chunk[0] + chunk[2]) / 2;
	return (chunk);
}

void	sort_medium(t_node **a, t_node **b, int argc)
{
	int		chunk_size;
	int		j;
	int		chunk[3];
	int		i;

	chunk[0] = 0;
	j = 0;
	chunk_size = chunk_sizer(argc);
	while (j < argc / chunk_size)
	{
		chunk_mover(chunk, chunk_size, argc);
		i = 0;
		while (i < chunk_size)
		{
			if ((*a)->index >= chunk[0] && (*a)->index < chunk[2])
			{
				pb(a, b);
				i++;
				if ((*b)->index < chunk[1])
					rb(b);
			}
			else
				ra(a);
		}
		j++;
	}
}
