/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 22:24:01 by rpokorny          #+#    #+#             */
/*   Updated: 2026/11/08 18:49:52 by rpokorny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	maximal_bit(int argc)
{
	int	size;
	int	max_bit;

	size = argc - 2;
	max_bit = 0;
	while (size > 0)
	{
		size /= 2;
		max_bit++;
	}
	return (max_bit);
}

void	sort_complex(t_data *data)
{
	int	bit;
	int	max_bit;
	int	i;

	bit = 0;
	max_bit = maximal_bit(data->size);
	while (bit < max_bit)
	{
		i = 0;
		while (i < data->size - 1)
		{
			if (((data->a->index >> bit) & 1) == 0)
				pb(data);
			else
				ra(data);
			i++;
		}
		while ((data->b) != NULL)
			pa(data);
		bit++;
	}
}
