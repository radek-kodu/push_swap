/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 19:31:12 by rpokorny          #+#    #+#             */
/*   Updated: 2026/09/16 20:50:51 by rpokorny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int compute_disorder(int *nbs, int size)
{
    int mistakes;
    int total_pairs;
    int i;
    int j;

    mistakes = 0;
    total_pairs = 0;
    i = 0;
    j = 0;
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
