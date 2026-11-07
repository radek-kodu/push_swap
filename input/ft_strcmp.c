/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:45:46 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/07 16:46:01 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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