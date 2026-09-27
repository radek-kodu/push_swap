/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:45:32 by jrosette          #+#    #+#             */
/*   Updated: 2026/09/27 12:40:16 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static char	**add_to_array(char **array, char *string);
static char	**calloc_plus(int total, int size);
static int	get_total(char **argv, int i);
static int	find_freeslot(char **array);

char	**parse(int argc, char **argv)
{
	int		i;
	char	**array;
	int		total;

	i = 1;
	if (argc == 1 || !argv[i])
		return (NULL);
	array = NULL;
	total = get_total(argv, i);
	array = calloc_plus((total + 1), sizeof(char *));
	if (!array)
		return (NULL);
	while (argv[i])
	{
		array = add_to_array(array, argv[i]);
		if (!array)
			return (NULL);
		i++;
	}
	return (array);
}

static char	**add_to_array(char **array, char *string)
{
	int	start;
	int	i;
	int	j;
	int	length;

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

static char	**calloc_plus(int count, int size)
{
	char	**array;
	int		i;

	if (count && size > (SIZE_MAX / count))
		return (NULL);
	array = malloc(count * size);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}

static int	get_total(char **argv, int i)
{
	int	total;
	
	while (argv[i])
	{
		if (!is_valid_string(argv[i]))
			return (NULL);
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
