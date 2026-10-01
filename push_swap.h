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
# define INT_MAX 2147483647
# define INT_MIN -2147483648

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_overnode
{
	t_node	*top;
	int		length;
}	t_overnode;

typedef struct	s_flags
{
	int	strategy;
	int	bench;
	int	start;
}	t_flags;

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
/*Input Utilities*/
char	**parse_nbrs(char **argv, int start);
t_flags	*parse_flags(char **argv);
int	    is_empty_string(char *input);
int     is_digit(char c);
int	    is_whitespace(char c);
int		is_sign(char c);
int	    is_valid_nbrs(char *input);
int	    count_numbers(char *string);
int	    find_length(char *string, int *start);
char	*ft_substr(char const *s, unsigned int start, int len);
char	**calloc_plus(int count, int size);
int	    ft_strcmp(const char *s1, const char *s2);
void    free_array(char **array);
/*Stack Utilities*/
t_node  *lastnode(t_node *a);
t_node	*find_min(t_node *a);
int     get_node_position(t_node *a, t_node *node);
int     get_stack_size(t_node *a);
void	bring_node_top(t_node **a, int node_pos);
t_node	*new_node(int value);
int	    is_duplicate(int nbr, t_node *stack);
void    stack_add_back(t_node **stack, t_node *new);
/*Sort Algorithms*/
void	sort_two(t_node **a);
void	sort_three(t_node **a);
void    sort_small(t_node **a, t_node **b);

#endif