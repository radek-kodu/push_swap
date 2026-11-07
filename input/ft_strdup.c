/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:24:02 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/07 17:28:05 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
