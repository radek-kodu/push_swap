/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 19:42:19 by rpokorny          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/09/17 13:12:47 by camille          ###   ########.fr       */
=======
/*   Updated: 2026/09/17 17:17:58 by rpokorny         ###   ########.fr       */
>>>>>>> 4970769 (some experiments)
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
<<<<<<< HEAD
}					t_node;
=======
 } t_node;

typedef struct s_overnode
{
	t_node	*top;
	int		length;
}	t_overnode;
>>>>>>> 4970769 (some experiments)

int compute_disorder(int *nbs, size_t size);
/*Operations*/
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
/*Stack Utilities*/
t_node *lastnode(t_node *a);
t_node	*find_min(t_node *a);
int node_position(t_node *a, t_node *node);
int	get_stack_size(t_node *a);

#endif