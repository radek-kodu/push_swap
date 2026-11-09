/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:19:15 by rpokorny          #+#    #+#             */
/*   Updated: 2026/11/09 18:35:46 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(int *nbs, int size)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size - 1)
		{
			total_pairs++;
			if (nbs[i] > nbs[j])
				mistakes++;
		}
	}
	return (mistakes / total_pairs);
}
