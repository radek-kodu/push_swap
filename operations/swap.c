/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:28:20 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/03 21:03:49 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_toptwo(t_node **c)
{
	t_node *temp_ptr;
	
	/* if 0 or 1 nodes, return*/
	if (*c == NULL || (*c)->next == NULL)
		return ;
	/*have a temp ptr point to 2nd node*/
	temp_ptr = (*c)->next;
	/* have 1st node point to 3rd node*/
	(*c)->next = (*c)->next->next;
	/* make 2nd node point to 1st node*/
	temp_ptr->next = *c;
	/* make **c point to new 1st node*/
	*c = temp_ptr; 
}

// static void	swap_toptwo(t_node **c)
// {
//     int temp_value;
//     int temp_index;

//     /* if 0 or 1 nodes, return*/
//     if (*c == NULL)
//         return ;
//     if ((*c)->next == NULL)
//         return ;
//     /*switch values*/
//     temp_value = (*c)->value;
//     (*c)->value = (*c)->next->value;
//     (*c)->next->value = temp_value;
//     /*also switch index*/
//     temp_index = (*c)->index;
//     (*c)->index = (*c)->next->index;
//     (*c)->next->index = temp_index;
// }

void	sa(t_node **a)
{
	swap_toptwo(a);
}

void	sb(t_node **b)
{
	swap_toptwo(b);
}

void	ss(t_node **a, t_node **b)
{
	swap_toptwo(a);
	swap_toptwo(b);
}