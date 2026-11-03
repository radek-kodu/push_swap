/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:28:04 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/03 21:08:02 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	t_node *secondlast(t_node *x)
{
	if (!x || !x->next)
		return (NULL);
	while (x->next->next != NULL)
		x = x->next;
	return (x);
}

/* Shift down all elements of the stack by one.
The last element becomes the first one.*/
static void	reverse_rotate(t_node **x)
{
	t_node	*temp;
	t_node	*newlast;
	// handle if 0 or 1 node
	if (*x == NULL || (*x)->next == NULL)
		return ;
	// get last node of x and save to temp
	temp = lastnode(*x);
	// disconnect temp from x, attach end of x to null
	newlast = secondlast(*x);
	newlast->next = NULL;
	// reattach temp to before the first node of x (making it first node)
	temp->next = *x;
	// make x point to new first node
	*x = temp;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
