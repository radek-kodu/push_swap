/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:45:32 by jrosette          #+#    #+#             */
/*   Updated: 2026/09/26 16:11:15 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static char	**add_to_array(char **array, char *string);
static char	**calloc_plus(int total, int size);

char	**parse(int argc, char **argv)
{
	int		i;
	char	**array;
	int		total;

	if (argc == 1)
		return (NULL);
	i = 1;
	if (!argv[i])
		return (NULL);
	array = NULL;
	total = 0;
	while (argv[i])
	{
		if (!is_valid_string(argv[i]))
			return (NULL);
		total += count_numbers(argv[i]);
		i++;
	}
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

static char	**add_to_array(char **array, char *string)
{
	int	start;
	int	i;
	int	j;
	int	length;

	start = 0;
	i = 0;
	while (array[i])
		i++;
	while (string[start])
	{
		length = find_length(string, &start);
		array[i] = malloc(length + 1);
        if (!(array[i]))
            return (NULL);
		j = 0;
		while (j < length)
		{
			array[i][j] = string[start + j];
			j++;
		}
		array[i][j] = '\0';
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
