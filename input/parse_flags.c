/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 16:47:02 by jrosette          #+#    #+#             */
/*   Updated: 2026/09/27 15:29:59 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Values of struct:
	strategy - 0 to 3
		0 - no selector given, uses adaptive as default
		1 - simple
		2 - complex
		3 - medium
	bench - 0 or 1, if "--bench" is included or not
	start - 0 to 3, starting index of the numbers
	
Possible options: 
./push_swap --simple --bench 4 3 2 1
./push_swap --bench --complex 4 3 2 1
./push_swap --simple 4 3 2 1
./push_swap 4 3 2 1

For error handling, start = -1
*/

t_flags	parse_flags(int argc, char **argv)
{
	t_flags	flags;
	int		i;
	int		limit;
	int		valid;
	
	if (argc == 1)
		return ((t_flags){0, 0, -1});
	flags.strategy = 0;
	flags.bench = 0;
	flags.start = 0;
	i = 1;
	limit = 3;
	
	while (i < limit)
	{
		if (!(is_validflag(argv[i])))
			return ((t_flags){0, 0, -1});
		flags = assign_flag(argv[i]);
		i++;	
	}
	return (flags);
}

// Function that checks if the flag is valid
static int	is_validflag(char *string)
{
	
}

// assigns the flag and checks for duplications
// edge case: ./push_swap --simple --complex 4 3 2 1
static t_flags	assign_flag(argv[i])
{
	
}