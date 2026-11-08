/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:45:32 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/08 19:18:12 by jrosette         ###   ########.fr       */
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
static void add_to_array(char **array, char **string);
// static long int	get_total(char **argv, int i);
static int	find_freeslot(char **array);

char	**parse_nbrs(char *input, int start)
{
	char	*array;
	int		total_elements;

	input += start;
	if (!input)
		return (NULL);
	array = NULL;
	if (!is_valid_nbrs(input))
		return (NULL);
	total_elements = count_numbers(input);
	array = calloc_plus((total_elements + 1), sizeof(char *));
	if (!array)
		return (NULL);
	/* BUGGY AREA BELOW: TO FIX */
	while (input)
	{
		while (is_whitespace(*input))
			input++;
		add_to_array(&array, &input);
		if (!array)
			return (NULL);
	}
	return (array);
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

static void add_to_array(char **array, char **string)
{
	int start;
	int i;
	int length;

	start = 0;
	i = find_freeslot(array);
	while (string[start])
	{
		length = find_length(*string, &start);
		array[i] = ft_substr(*string, start, length);
		if (!(array[i]))
		{
			free_array(array);    
			return (NULL);
		}
		start += length;
		i++;
	}
	string += length;
	array[i] = NULL;
	return (array);
}

static int	find_freeslot(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	main(void)
{
	char	**array;
	int 	i = 0;

	char	input[] =  "--simple --bench 10 5 7 12 57 42359";
	int		start = 17;
	array = parse_nbrs(input, start);
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;		
	}
	return (0);
}

// static long int	get_total(char **argv, int i)
// {
// 	long int	total;
	
// 	total = 0;
// 	while (argv[i])
// 	{
// 		if (!is_valid_nbrs(argv[i]))
// 			return (-1);
// 		total += count_numbers(argv[i]);
// 		if (total > INT_MAX)
// 			return (-1);
// 		i++;
// 	}
// 	return (total);
// }