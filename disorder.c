/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:19:15 by rpokorny          #+#    #+#             */
/*   Updated: 2026/11/09 22:28:12 by rpokorny         ###   ########.fr       */
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
	while (i + 1 < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (nbs[i] > nbs[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / total_pairs);
}
