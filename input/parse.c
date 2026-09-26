/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:45:32 by jrosette          #+#    #+#             */
/*   Updated: 2026/09/26 13:19:10 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_valid_string(char *input)
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

/*SHORTEN FUNCTION -- maybe copy_number*/
static char	**add_to_array(char **array, char *string)
{
	int	start;
	int	end;
	int	i;
	int	j;
	int	length;

	start = 0;
	i = 0;
	while (array[i])
		i++;
	while (string[start])
	{
		while (is_whitespace(string[start]))
			start++;
		end = start;
		while (is_digit(string[end]) || is_sign(string[end]))
			end++;
		length = end - start;
		array[i] = malloc(length + 1);
		j = 0;
		while (start < end)
		{
			array[i][j] = string[start];
			start++;
			j++;
		}
		array[i][j] = '\0';
		i++;
	}
	array[i] == NULL;
	return (array);
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
			if (is_whitespace(string[i + 1]) || string[i + 1])
				count++;
		i++;
	}
	return (count);
}

char	**parse(int argc, char **argv)
{
	int		i;
	int		j;
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
			return (0);
		total += count_numbers(argv[i]);
		i++;
	}
	array = malloc((total + 1) * sizeof(char *));
	i = 0;
	while (i <= total)
	{
		array[i] = NULL;
		i++;
	}	
	i = 1;
	while (argv[i])
	{
		array = add_to_array(array, argv[i]);
		i++;
	}
	return (array);
}
