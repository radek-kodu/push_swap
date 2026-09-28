/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 16:47:02 by jrosette          #+#    #+#             */
/*   Updated: 2026/09/28 21:56:22 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Values of struct:
	strategy - 1 to 4
		0 - no strategy flag
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

static int	is_validflag(char *string);
static t_flags	*assign_flag(char *string, t_flags *flags);
static int	is_flag_available(char *string, t_flags *flags);

// Does not check argc
t_flags	*parse_flags(char **argv)
{
	t_flags	*flags;
	int		i;
	
	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	(*flags).strategy = 0;
	(*flags).bench = 0;
	(*flags).start = 0;
	i = 1;
	
	while (argv[i] && !(is_valid_nbrs(argv[i])))
	{
		if ((is_validflag(argv[i])) == 0)
		{
			(*flags).start = -1;	
			return (flags);
		}
		flags = assign_flag(argv[i], flags);
		if ((*flags).start == -1)
			return (flags);
		i++;	
	}
	(*flags).start = i;
	return (flags);
}

// Function that checks if the flag is valid
// only acceptable strings are: --bench, --simple, --medium, --complex, --adaptive
// Returns 1 if valid flag
// Returns 0 if not valid flag
static int	is_validflag(char *string)
{
	
	if (ft_strcmp(string, "--bench") == 0
		|| ft_strcmp(string, "--simple") == 0
		|| ft_strcmp(string, "--medium") == 0
		|| ft_strcmp(string, "--complex") == 0
		|| ft_strcmp(string, "--adaptive") == 0)
		return (1);
	else
		return (0);
}

// assigns the flag to struct values and checks for duplications 
// For duplications, flags.start = -1
// edge case: ./push_swap --adaptive --complex 4 3 2 1
// edge case: ./push_swap --bench --bench 4 3 2 1
static t_flags	*assign_flag(char *string, t_flags *flags)
{
	if (!(is_flag_available(string, flags)))
	{
		(*flags).start = -1;
		return (flags);
	}	
	else
	{
		if (ft_strcmp(string, "--bench") == 0)
			(*flags).bench = 1;
		else if (ft_strcmp(string, "--adaptive") == 0)
			(*flags).strategy = 1;
		else if (ft_strcmp(string, "--simple") == 0)
			(*flags).strategy = 2;
		else if (ft_strcmp(string, "--medium") == 0)
			(*flags).strategy = 3;
		else if (ft_strcmp(string, "--complex") == 0)
			(*flags).strategy = 4;				
	}
	return (flags);
}

static int	is_flag_available(char *string, t_flags *flags)
{
	if ((*flags).bench != 0 && ft_strcmp(string, "--bench") == 0)
		return (0);
	else if ((*flags).strategy != 0 && (ft_strcmp(string, "--simple") == 0
		|| ft_strcmp(string, "--medium") == 0
		|| ft_strcmp(string, "--complex") == 0
		|| ft_strcmp(string, "--adaptive") == 0))
		return (0);
	return (1);
}
