/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 20:13:02 by rpokorny          #+#    #+#             */
/*   Updated: 2026/09/17 17:29:00 by rpokorny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *atoi_plus(int argc, char **argv)
{
    int *nbs;
    int i;
    int j;

    nbs = malloc(argc * sizeof(int));
    if (nbs == NULL)
        return (NULL);
    i = 0;
    while (argv[i])
    {
        nbs[i] = 0;
        j = 0;
        while (argv[i][j])
        {
            nbs[i] = nbs[i] * 10 + (argv[i][j] - '0');
            j++;
        }
        i++;
    }
    return (nbs);    
}