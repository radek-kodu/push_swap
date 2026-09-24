/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:45:32 by jrosette          #+#    #+#             */
/*   Updated: 2026/09/24 21:01:17 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_valid_string(char* input)
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
		i++;
	}
	return (1);
}

static char	**add_to_array(char** array, char *string)
{
	int	i;
	int	j;

	i = 0;
	while (is_whitespace(string[i]))
		i++;
	while (string[i])
	{
		j = i;
		while (is_digit(string[i]) || string[i] == '+' || string[i] == '-')
			j++;
		// add string[i] to string[j] into array
	}
}

char	**parse(int argc, char **argv)
{
	int		i;
	int		j;
	char	**array;

	if (argc == 1)
		return ;
	i = 1;
	if (!argv[i])
		return ;
	while (i < argc && argv[i])
	{
		// confirms that string isn't empty
		// confirms that string contains only one +/-, digits & whitespace
		if (!is_valid_string(argv[i]))
			return (0);
		// add number to array
		// if string contains whitespace, split chars
		array = add_to_array(array, argv[i]);
	}
	return (array);
}