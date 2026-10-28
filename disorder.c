/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:19:15 by rpokorny          #+#    #+#             */
/*   Updated: 2026/10/28 18:30:54 by rpokorny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_disorder(char *nbs, int length)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	i = 0;
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length - 1)
		{
			total_pairs++;
			if (nbs[i] > nbs[j])
				mistakes++;
		}
	}
	return (mistakes / total_pairs);
}
