/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:17:18 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/04 20:01:15 by rpokorny         ###   ########.fr       */
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
	chunk[0] = chunk[2];
	chunk[2] = chunk[0] + chunk_size;
	if (chunk[2] > argc)
		chunk[2] = argc;
	chunk[1] = (chunk[0] + chunk[2]) / 2;
	return (chunk);
}

void    push_chunk(t_node **a, t_node **b, int chunk[3])
{
    int i;

    i = 0;
    while (*a && i < chunk[2] - chunk[0])
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
}

void	sort_medium(t_node **a, t_node **b, int argc)
{
	int		chunk_size;
	int		chunk[3];

	chunk[0] = 0;
	chunk_size = chunk_sizer(argc);
	chunk[2] = chunk_size;
	chunk[1] = chunk[2] / 2;
	while (chunk[0] < argc)
	{
		push_chunk(a, b, chunk);
		chunk_mover(chunk, chunk_size, argc);
	}
}
