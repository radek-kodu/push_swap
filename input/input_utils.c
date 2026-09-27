/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camille <camille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 15:44:51 by jrosette          #+#    #+#             */
/*   Updated: 2026/09/27 16:11:00 by camille          ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, int len)
{
	unsigned int	j;
	char			*substr;
	int 			slen;

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

	if (count && size > (SIZE_MAX / count))
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