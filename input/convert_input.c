/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 13:14:45 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/12 12:49:46 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Converts user input into a string.
*/

static int	get_line_length(int argc, char **argv);

char	*convert_input(int argc, char **argv)
{
	char	*user_input;
	int		line_length;
	int		i;
	int		j;
	int		k;

	line_length = get_line_length(argc, argv);
	if (line_length == 0)
		return (NULL);
	user_input = malloc(line_length + 1);
	if (!user_input)
		return (NULL);
	i = 0;
	j = 1;
	while (j < argc)
	{
		k = 0;
		while (argv[j][k])
			user_input[i++] = argv[j][k++];
		if (j != (argc - 1))
			user_input[i++] = ' ';
		j++;
	}
	user_input[i] = '\0';
	return (user_input);
}

static int	get_line_length(int argc, char **argv)
{
	int	i;
	int	line_length;

	i = 1;
	line_length = 0;
	while (i < argc)
	{
		line_length += ft_strlen(argv[i]);
		if (i != (argc -1))
			line_length++;
		i++;
	}
	return (line_length);
}

/*
int	main(int argc, char	**argv)
{
	char	*input;

	input = convert_input(argc, argv);	
	printf("%s", input);
	free(input);
	return (0);	
}
*/