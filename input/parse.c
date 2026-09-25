/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:45:32 by jrosette          #+#    #+#             */
/*   Updated: 2026/09/24 22:15:42 by camille          ###   ########.fr       */
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
		else if (input[i] == '+' || input[i] == '-') 
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
static char	**add_to_array(char** array, char *string)
{
	int	start;
	int	end;
	int	i;
	int	j;
	int length;

	start = 0;
	i = 0;
	while (array[i])
		i++;
	while (string[start])
	{
		while (is_whitespace(string[start]))
			start++;
		end = start;
		while (is_digit(string[end]) || string[end] == '+' || string[end] == '-')
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
	return (array);
}

static int	count_numbers(char *string)
{
	/* TO DO*/
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
	while (i < argc && argv[i])
	{
		// confirms that string isn't empty
		// confirms that string contains only one +/-, digits & whitespace
		if (!is_valid_string(argv[i]))
			return (0);
		// allocate memory by counting numbers + 1 (for NULL)
		total = count_numbers(argv[i]);
		
		// add number to array
		// if string contains whitespace, split chars
		array = add_to_array(array, argv[i]);
		i++;
	}
	return (array);
}