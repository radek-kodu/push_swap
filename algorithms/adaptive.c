/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:48:17 by rpokorny          #+#    #+#             */
/*   Updated: 2026/11/04 12:35:22 by rpokorny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_flags	*adaptive(int *nbs, int argc, t_flags *flags)
{
	int	disorder;

	disorder = compute_disorder(nbs, argc);
	if (disorder < 0.2)
	{
		flags->strategy = 2;
		return (flags);
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		flags->strategy = 3;
		return (flags);
	}
	else
	{
		flags->strategy = 4;
		return (flags);
	}
}
