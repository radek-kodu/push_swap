/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 15:44:51 by jrosette          #+#    #+#             */
/*   Updated: 2026/09/26 16:11:05 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_empty_string(char *input)
{
	int	i;
	int char_flag;

	i = 0;
	char_flag = 0;
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

int	is_valid_string(char *input)
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

int	count_numbers(char *string)
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

int	find_length(char *string, int *start)
{
	int	end;

	while (is_whitespace(string[*start]))
		(*start)++;
	end = *start;
	while (is_digit(string[end]) || is_sign(string[end]))
		end++;
	return (end - *start);
}