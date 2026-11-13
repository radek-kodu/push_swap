/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:48:17 by rpokorny          #+#    #+#             */
/*   Updated: 2026/11/13 20:54:39 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_adaptive(t_flags *flags, t_data *data)
{
	if (flags->disorder < 0.2)
	{
		sort_simple(data);
	}
	else if (flags->disorder < 0.5)
	{
		sort_medium(data);
	}
	else
	{
		sort_complex(data);
	}
}
