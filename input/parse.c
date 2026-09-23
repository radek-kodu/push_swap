/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:45:32 by jrosette          #+#    #+#             */
/*   Updated: 2026/09/23 15:46:52 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_empty_string(char *input)
{
	int	i;
	int char_flag;

	i = 0;
	while (input[i])
	{
		if (!(input[i] == ' ' || (input[i] >= 9 && input[i] <= 13)))
			char_flag++;
		i++;
	}
	if (char_flag > 0)
		return (0);
	return (1);
}

static int	is_valid_string(char* input)
{
	int	i;
	int	sign_flag;
	
	i = 0;
	sign_flag = 0;
	if (is_empty_string(input))
		return ;
	while (input[i])
	{
		if (input[i] == ' ' || (input[i] >= 9 && input[i] <= 13))
		 	i++;
		else if (input[i] == '+' || input[i] == '-') 
		{
			if (sign_flag > 0)
				return (0);
			else
				sign_flag++;			
		}
		else if (!(input[i] >= '0' && input[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

char **add_to_array(char** array, char *string)
{
	int	i;
	int	j;

	i = 0;
	while (string[i] == ' ' || (string[i] >= 9 && string[i] <= 13))
		i++;
	while (string[i])
	{
		j = i;
		while ((string[i] >= '0' && string[i] <= '9')|| string[i] == '+' || string[i] == '-')
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