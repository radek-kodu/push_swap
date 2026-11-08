/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 19:42:19 by rpokorny          #+#    #+#             */
/*   Updated: 2026/11/08 19:23:12 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_flags
{
	int		strategy;
	int		bench;
	int		start;
	double	disorder;
}	t_flags;

typedef struct s_data
{
	t_node	*a;
	t_node	*b;
	t_bench bench;
	int		size;
}	t_data;

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_bench;

double	compute_disorder(int *nbs, int argc);
/*Operations*/
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
/*Input Utilities*/
char	**parse_nbrs(char *input, int start);
t_flags	*parse_flags(char *args);
int	    is_empty_string(char *input);
int     is_digit(char c);
int	    is_whitespace(char c);
int		is_sign(char c);
int	    find_length(char *string, int *start);
char	*ft_substr(char const *s, int start, int len);
char	**calloc_plus(int count, int size);
int		ft_strcmp(const char *s1, const char *s2);
void	free_array(char **array);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, int n);

/*Stack Utilities*/
int		is_sorted(t_node *a);
t_node	*lastnode(t_node *a);
t_node	*find_min(t_node *a);
int		get_node_position(t_node *a, t_node *node);
int		get_stack_size(t_node *a);
void	bring_node_top(t_node **a, int node_pos);
t_node	*new_node(int value);
int		is_duplicate(int nbr, t_node *stack);
void	stack_add_back(t_node **stack, t_node *new);
t_node	*free_stack(t_node *stack);
t_node	*ft_lstnew(int content);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	stack_clear(t_node **a);
void	print_bench(t_data *data, t_flags flags);

/*Sort Algorithms*/
void	sort_two(t_data *data);
void	sort_three(t_data *data);
void	sort_small(t_data *data);
void	sort_medium(t_data *data);
void	sort_complex(t_data *data);
void	sort_adaptive(t_flags *flags);

#endif
