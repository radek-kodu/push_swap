/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 15:44:51 by jrosette          #+#    #+#             */
/*   Updated: 2026/09/26 14:59:04 by jrosette         ###   ########.fr       */
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

