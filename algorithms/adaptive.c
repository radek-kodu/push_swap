/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:48:17 by rpokorny          #+#    #+#             */
/*   Updated: 2026/11/08 17:32:05 by rpokorny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_flags *flags)
{
	if (flags->disorder < 0.2)
	{
		flags->strategy = 2;
	}
	else if (flags->disorder < 0.5)
	{
		flags->strategy = 3;
	}
	else
	{
		flags->strategy = 4;
	}
}
