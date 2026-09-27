/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 16:47:02 by jrosette          #+#    #+#             */
/*   Updated: 2026/09/27 17:11:15 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Values of struct:
	strategy - 1 to 4
		1 - adaptive
		2 - simple
		3 - complex
		4 - medium
	bench - 0 or 1, if "--bench" is included or not
	start - 0 to 3, starting index of the numbers
	
Possible options: 
./push_swap --simple --bench 4 3 2 1
./push_swap --bench --complex 4 3 2 1
./push_swap --simple 4 3 2 1
./push_swap 4 3 2 1

For error handling, start = -1 (flags are a mistake)
How to handle no flags?
*/

static int	set_start(t_flags *flags);
static t_flags	*assign_flag(char *string, t_flags *flags);
static int	is_validflag(char *string);

t_flags	*parse_flags(int argc, char **argv)
{
	t_flags	*flags;
	int		i;
	int		limit;
	int		valid;
	
	if (argc == 1)
		return (&((t_flags){0, 0, -1}));
	(*flags).strategy = 0;
	(*flags).bench = 0;
	(*flags).start = 0;
	i = 1;
	limit = 3;
	
	while (i < limit)
	{
		if ((is_validflag(argv[i])) < 0)
			return (&((t_flags){0, 0, -1}));
		flags = assign_flag(argv[i], flags);
		i++;	
	}
	(*flags).start = set_start(flags);
	return (flags);
}

// Function that checks if the flag is valid
// only acceptable strings are: --bench, --simple, --medium, --complex, --adaptive
// Returns 0 if the string are valid numbers
static int	is_validflag(char *string)
{
	
	if (ft_strcmp(string, "--bench") || ft_strcmp(string, "--simple"
		|| ft_strcmp(string, "--medium") || ft_strcmp(string, "--complex")
		|| ft_strcmp(string, "--adaptive")))
		return (1);
	else if (is_valid_string(string))
		return (0);
	else
		return (-1);
}

// assigns the flag to struct values and checks for duplications (flags.start = -1)
// edge case: ./push_swap --adaptive --complex 4 3 2 1
// edge case: ./push_swap --bench --bench 4 3 2 1
static t_flags	*assign_flag(char *string, t_flags *flags)
{
	
	if (is_valid_string(string))
		return (flags);
	else if ((*flags).bench != 0 || (*flags).strategy != 0)
		return ((*flags).start == -1);
	else
	{
		if (string == "--bench")
			return ((*flags).bench = 1);
		else if (string == "--adaptive")
			return ((*flags).strategy = 1);
		else if (string == "--simple")
			return ((*flags).strategy = 2);
		else if (string == "--medium")
			return ((*flags).strategy = 3);
		else if (string == "--complex")
			return ((*flags).strategy = 4);						
	}
	return (flags);
}

static int	set_start(t_flags *flags)
{
	int start;

	start = 0;
	if 	((*flags).bench != 0 && (*flags).strategy != 0)
		start = 3;
	else if ((*flags).bench != 0 || (*flags).strategy != 0)
		start = 2;
	else
		start = 1;
	return (start);
}
