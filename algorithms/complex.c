/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 22:24:01 by rpokorny          #+#    #+#             */
/*   Updated: 2026/11/06 20:43:58 by rpokorny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	maximal_bit(int argc)
{
	int	size;
	int	max_bit;

	size = argc - 1;
	max_bit = 0;
	while (size > 0)
	{
		size /= 2;
		max_bit++;
	}
	return (max_bit);
}

void	complex(t_node **a, t_node **b, int argc)
{
	int	bit;
	int	max_bit;
	int	i;

	bit = 0;
	max_bit = maximal_bit(argc);
	while (bit < max_bit)
	{
		i = 0;
		while (i < argc - 2)
		{
			if ((((*a)->index >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while ((*b) != NULL)
			pa(a, b);
		bit++;
	}
}
