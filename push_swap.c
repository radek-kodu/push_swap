/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 19:29:36 by rpokorny          #+#    #+#             */
/*   Updated: 2026/11/13 20:53:23 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nbs_conversion(int *nbs, t_data *data)
{
	t_node	*new;
	int		i;

	i = 0;
	while (i < data->size)
	{
		new = ft_lstnew(nbs[i]);
		if (new == NULL)
		{
			stack_clear(&data->a);
			return (0);
		}
		ft_lstadd_back(&data->a, new);
		i++;
	}
	return (1);
}

void	sorting(t_data *data, t_flags flags)
{
	if (flags.disorder == 0)
	{
		if (flags.bench == 1)
			print_bench(data, flags);
		return ;
	}
	indexing(data->a);
	if (flags.strategy == 0 || flags.strategy == 1)
		sort_adaptive(&flags, data);
	if (data->size <= 5)
		sort_small(data);
	else if (flags.strategy == 2)
		sort_simple(data);
	else if (flags.strategy == 3)
		sort_medium(data);
	else
		sort_complex(data);
	if (flags.bench == 1)
		print_bench(data, flags);
}

static int	prepare_input(int argc, char **argv, t_flags *flags, t_data *data)
{
	char	*input;
	int		*nbs;

	input = convert_input(argc, argv);
	if (!input)
		return (0);
	if (!parse_flags(input, flags))
		return (free(input), 0);
	nbs = NULL;
	if (!parse_nbrs(input, flags->start, &nbs, &data->size))
		return (free(input), 0);
	free(input);
	flags->disorder = compute_disorder(nbs, data->size);
	if (!nbs_conversion(nbs, data))
		return (free(nbs), 0);
	free(nbs);
	return (1);
}

int	main(int argc, char **argv)
{
	t_flags	flags;
	t_data	data;

    if (argc == 1)
        return (0);
	data = (t_data){0};
	flags = (t_flags){0};
	if (!prepare_input(argc, argv, &flags, &data))
		return (write(2, "Error\n", 6), 1);
	sorting(&data, flags);
	stack_clear(&data.a);
	stack_clear(&data.b);
	return (0);
}

/*
//fprintf(stderr, "Strategy selected: %d\n", flags.strategy);
	//#include <stdio.h>
	//t_node	*tmp;

	//tmp = data->a;
	//while (tmp)
	//{
	//	fprintf(stderr, "%d ", tmp->value);
	//	tmp = tmp->next;
	//}
	//fprintf(stderr, "\n");
*/