/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 19:29:36 by rpokorny          #+#    #+#             */
/*   Updated: 2026/11/04 12:18:40 by rpokorny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int *sorting(int *nbs, int disorder)
{

}
void push_swap(int argc, char **argv)
{
    int     *nbs;
    t_flags *flags;


    nbs = malloc(argc * sizeof(int));
    if (nbs == NULL)
        return (write(2, "Error\n", 6), free(nbs), 1);
    nbs = atoi_plus(argc, &argv);
    if (nbs == NULL)
        return (write(2, "Error\n", 6), free(nbs), 1);
    flags = parse_flags(argv, flags);
    nbs = sorting(nbs, flags->disorder);
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return (write(2, "Error\n", 6), 1);

    push_swap(argc - 1, &argv[1]);

    return (0);
}