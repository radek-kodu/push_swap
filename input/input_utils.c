/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 15:44:51 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/09 17:01:21 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_empty_string(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!(input[i] == ' ' || (input[i] >= 9 && input[i] <= 13)))
			return (0);
		i++;
	}
	return (1);
}

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int	is_whitespace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	find_length(char *string, int *start)
{
	int	end;

	end = *start;
	while (is_digit(string[end]) || is_sign(string[end]))
		end++;
	return (end - *start);
}
