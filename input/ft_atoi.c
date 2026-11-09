/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 20:13:02 by rpokorny          #+#    #+#             */
/*   Updated: 2026/11/09 11:11:03 by camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(char *str, long *result)
{
	int			i;
	long		sign;
	long		digit;

	i = 0;
	*result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';
		if (sign == 1 && (*result > LONG_MAX / 10
				|| (*result == LONG_MAX / 10
					&& digit > LONG_MAX % 10)))
			return (0);
		if (sign == -1 && (*result > LONG_MAX / 10
				|| (*result == LONG_MAX / 10
					&& digit > 8)))
			return (0);
		*result = (*result * 10) + digit;
		i++;
	}
	*result *= sign;
	return (1);
}
