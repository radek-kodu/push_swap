/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:45:32 by jrosette          #+#    #+#             */
/*   Updated: 2026/09/28 20:19:26 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*
Insert flags.start as parameter int start.
TO DO: fix possible memory leaks
*/

static char	**add_to_array(char **array, char *string);
static int	get_total(char **argv, int i);
static int	find_freeslot(char **array);

char	**parse_nbrs(char **argv, int start)
{
	char	**array;
	int		total;

	if (!argv[start])
		return (NULL);
	array = NULL;
	total = get_total(argv, start);
	if (total <= 0)
		return (NULL);
	array = calloc_plus((total + 1), sizeof(char *));
	if (!array)
		return (NULL);
	while (argv[start])
	{
		array = add_to_array(array, argv[start]);
		if (!array)
		{
			free_array(array);    
			return (NULL);
		}
		start++;
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
		{
			free_array(array);    
			return (NULL);
		}
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
