/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:34:53 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/07 17:35:06 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int				i;
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