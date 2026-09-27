/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:45:32 by jrosette          #+#    #+#             */
/*   Updated: 2026/09/27 18:28:41 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*
This version currently doesn't take into account flags yet.
Once a parser for algo & bench flags has been created, insert flags.start as param.
Use argv[flags.start] instead of argv[i]
Since flags are optional, flags.start can either be 2/ 3 / 4.
*/

static char	**add_to_array(char **array, char *string);
static int	get_total(char **argv, int i);
static int	find_freeslot(char **array);

char	**parse_nbrs(int argc, char **argv)
{
	int		i;
	char	**array;
	int		total;

	i = 1;
	if (argc == 1 || !argv[i])
		return (NULL);
	array = NULL;
	total = get_total(argv, i);
    if (total <= 0)
        return (NULL);
	array = calloc_plus((total + 1), sizeof(char *));
    if (!array)
        return (NULL);
    i = 1;
	while (argv[i])
	{
		array = add_to_array(array, argv[i]);
		if (!array)
			return (NULL);
		i++;
	}
	return (array);
}

static char **add_to_array(char **array, char *string)
{
    int start;
    int i;
    int length;

    start = 0;
    i = find_freeslot(array);
    while (string[start])
    {
        length = find_length(string, &start);
        array[i] = ft_substr(string, start, length);
        if (!(array[i]))
            return (NULL);
        start += length;
        i++;
    }
    array[i] = NULL;
    return (array);
}

static int	get_total(char **argv, int i)
{
	int	total;
	
    total = 0;
	while (argv[i])
	{
		if (!is_valid_nbrs(argv[i]))
			return (-1);
		total += count_numbers(argv[i]);
		i++;
	}
	return (total);
}

static int	find_freeslot(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
