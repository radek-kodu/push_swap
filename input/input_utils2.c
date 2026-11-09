/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:53:37 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/09 16:56:09 by jrosette         ###   ########.fr       */
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

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int					i;
	const unsigned char	*source;
	unsigned char		*destination;

	i = 0;
	source = src;
	destination = dst;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	count;

	count = ft_strlen(s1);
	ptr = malloc(1 + count);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, (count + 1));
	return (ptr);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}