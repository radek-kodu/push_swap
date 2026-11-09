/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:02:03 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/09 18:03:24 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_duplicate_nbrs(int number, int *numbers, int size);

char	*ft_substr(char const *s, int start, int len)
{
	int		j;
	char	*substr;
	int		slen;

	j = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (start + len > slen)
		substr = malloc((slen - start) + 1);
	else
		substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	while (j < len && s[start])
	{
		substr[j] = s[start];
		start++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}

char	**calloc_plus(int count, int size)
{
	char	**array;
	int		i;

	if (count && (unsigned long)size > (SIZE_MAX / count))
		return (NULL);
	array = malloc(count * size);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		array[i] = NULL;
		i++;
	}
	return (array);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	*validate(char **array, int total_elements)
{
	int		i;
	long	temp_value;
	int		*numbers;

	numbers = malloc(total_elements * sizeof(int));
	if (!numbers)
		return (free_array(array), NULL);
	i = 0;
	while (i < total_elements)
	{
		if (!ft_atoi(array[i], &temp_value))
			return (free(numbers), free_array(array), NULL);
		if (temp_value < INT_MIN || temp_value > INT_MAX
			|| is_duplicate_nbrs((int)temp_value, numbers, i))
			return (free(numbers), free_array(array), NULL);
		numbers[i] = (int)temp_value;
		i++;
	}
	free_array(array);
	return (numbers);
}

static int	is_duplicate_nbrs(int number, int *numbers, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (numbers[i] == number)
			return (1);
		i++;
	}
	return (0);
}