/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 14:26:00 by rpokorny          #+#    #+#             */
/*   Updated: 2026/11/04 15:57:15 by rpokorny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_node *a)
{
	t_node	*current;
	t_node	*comp;

	current = a;
	while (current)
	{
		current->index = 0;
		comp = a;
		while (comp)
		{
			if (current->value > comp->value)
				current->index++;
			comp = comp->next;
		}
		current = current->next;
	}
}
