/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:45:32 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/09 17:12:10 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*
Checks the format of the input:

* Split "3 42 -7" into individual strings
* Check for non-numeric characters
* Check sign placement
* Reject "+" / "-" with no digits
* Produces an array of chars

NOTE: Insert flags.start as parameter (int start).
*/

static int	is_valid_nbrs(char *input);
static int	count_numbers(char *string);
static int	add_to_array(char **array, char **string, int i);

int	parse_nbrs(char *input, int start, int **numbers_array, int *total_elements)
{
	char	**chars_array;
	int		i;

	input += start;
	if (!is_valid_nbrs(input))
		return (1);
	*total_elements = count_numbers(input);
	chars_array = calloc_plus((*total_elements + 1), sizeof(char *));
	if (!chars_array)
		return (1);
	i = 0;
	while (*input)
	{
		while (is_whitespace(*input))
			input++;
		if (!*input)
			break ;
		if (!add_to_array(chars_array, &input, i))
    		return (free_array(chars_array), 1);
		i++;
	}
	*numbers_array = validate(chars_array, *total_elements);
	if (!*numbers_array)
		return (1);
	return (0);
}

static int	is_valid_nbrs(char *input)
{
	int	i;

	i = 0;
	if (is_empty_string(input))
		return (0);
	while (input[i])
	{
		if (is_whitespace(input[i]))
			i++;
		else if (is_sign(input[i]))
		{
			if (i != 0 && !(is_whitespace(input[i -1])))
				return (0);
			else if (!(is_digit(input[i + 1])))
				return (0);
			i++;
		}
		else if (!(is_digit(input[i])))
			return (0);
		else
			i++;
	}
	return (1);
}

static int	count_numbers(char *string)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i])
	{
		while (is_whitespace(string[i]))
			i++;
		if (is_digit(string[i]) || is_sign(string[i]))
		{
			count++;
			if (is_sign(string[i]))
				i++;
			while (is_digit(string[i]))
				i++;
		}
	}
	return (count);
}

static int	add_to_array(char **array, char **string, int i)
{
	int	length;

	length = 0;
	while ((*string)[length] && !is_whitespace((*string)[length]))
		length++;
	array[i] = ft_substr(*string, 0, length);
	if (!(array[i]))
	{
		free_array(array);
		return (0);
	}
	*string += length;
	return (1);
}

/*
int	main(void)
{
	char	**array;
	int 	i = 0;
    int     total_elements;

	char	input[] =  "--simple --bench 10    5 7 -12 57 +42359";
	int		start = 17;
	array = parse_nbrs(input, start, &total_elements);
	while (i < total_elements)
	{
		printf("index %d: %s\n", i, array[i]);
		i++;		
	}
    free_array(array);
	return (0);
}
*/