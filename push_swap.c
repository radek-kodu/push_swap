/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpokorny <rpokorny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 19:29:36 by rpokorny          #+#    #+#             */
/*   Updated: 2026/11/09 22:31:11 by rpokorny         ###   ########.fr       */
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
	if (flags.strategy == 0 || flags.strategy == 1)
		sort_adaptive(&flags);
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

int	main(int argc, char **argv)
{
	t_flags	flags;
	t_data	data;
	int		*nbs;
	char	*input;

	data = (t_data){0};
	flags = (t_flags){0};
	input = convert_input(argc, argv);
	if (!parse_flags(input, &flags))
		return (write(2, "Error: flags\n", 13), 1);
	parse_nbrs(input, flags.start, &nbs, &data.size);
	free(input);
	if (!nbs)
		return (write(2, "Error: nbs\n", 12), 1);
	printf("Point 1\n");
	flags.disorder = compute_disorder(nbs, data.size);
	printf("Point 2\n");
	if (!nbs_conversion(nbs, &data))
	{
		free(nbs);
		return (write(2, "Error: conv\n", 13), 1);
	}
	free(nbs);
	sorting(&data, flags);
	stack_clear(&data.a);
	stack_clear(&data.b);
}
