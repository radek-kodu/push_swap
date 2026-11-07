/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosette <jrosette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:43:17 by jrosette          #+#    #+#             */
/*   Updated: 2026/11/07 19:48:11 by jrosette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Parses & checks the flags and saves them to a struct.

Values of struct:
	strategy - 1 to 4
		0 - no strategy flag
		1 - adaptive (default)
		2 - simple
		3 - medium
		4 - complex
	bench - 0 or 1, if "--bench" is included or not
	start - 0 to 3, starting index of the numbers
	
Possible options: 
./push_swap --simple --bench 4 3 2 1
./push_swap --bench --complex 4 3 2 1
./push_swap --simple 4 3 2 1
./push_swap 4 3 2 1

For error handling, start = -1 
*/

static int	is_validflag(char *string);
static t_flags	*assign_flag(char *string, t_flags *flags);
static int	is_flag_available(char *string, t_flags *flags);
static char	*get_flag(char *args, int *i);

t_flags	*parse_flags(char *args)
{
	t_flags	*flags;
	int		i;
	char	*flag;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	(*flags).strategy = 0;
	(*flags).bench = 0;
	(*flags).start = 0;
	
	i = 0;
	while (args[i])
	{		
		while (args[i] == ' ')		
			i++;	
		flag = get_flag(args, &i);
		// printf("flag: %s\n", flag);
		if (flag)
		{
			flags = assign_flag(flag, flags);
		}
		else if ((*flags).start == -1)
		{		
			free(flag);			
			return (flags);
		}
		else
			break;
		i++;
	}
	(*flags).start = i;
	free(flag);
	return (flags);
}

// returns a flag from input
static char	*get_flag(char *args, int *i)
{
	char	*flag;
	int		j;
	int		len;
	int		temp;

	// printf("index in value: %d\n", *i);
	temp = *i;
	len = 0;
	while (args[temp++] && args[temp++] != ' ')
		len++;
	flag = malloc(len + 1);
	if (!flag)
		return (NULL);
	j = 0;
	while (args[*i])
	{
		if (args[*i] == ' ' || is_digit(args[*i]))
			break ;
		flag[j] = args[*i];
		(*i)++;
		j++;
	}
	flag[j] = '\0';
	// printf("index out value: %d\n", *i);
	if (is_validflag(flag))
		return (flag);
	else
		return (NULL);
}

static int	is_validflag(char *string)
{
	
	if (ft_strcmp(string, "--bench") == 0
		|| ft_strcmp(string, "--simple") == 0
		|| ft_strcmp(string, "--medium") == 0
		|| ft_strcmp(string, "--complex") == 0
		|| ft_strcmp(string, "--adaptive") == 0)
		return (1);
	else
		return (0);
}

// assigns the flag to struct values and checks for duplications 
// For duplications, flags.start = -1
// edge case: ./push_swap --adaptive --complex 4 3 2 1
// edge case: ./push_swap --bench --bench 4 3 2 1
static t_flags	*assign_flag(char *string, t_flags *flags)
{
	if (!(is_flag_available(string, flags)))
	{
		(*flags).start = -1;
		return (flags);
	}	
	else
	{
		if (ft_strcmp(string, "--bench") == 0)
			(*flags).bench = 1;
		else if (ft_strcmp(string, "--adaptive") == 0)
			(*flags).strategy = 1;
		else if (ft_strcmp(string, "--simple") == 0)
			(*flags).strategy = 2;
		else if (ft_strcmp(string, "--medium") == 0)
			(*flags).strategy = 3;
		else if (ft_strcmp(string, "--complex") == 0)
			(*flags).strategy = 4;				
	}
	return (flags);
}

static int	is_flag_available(char *string, t_flags *flags)
{
	if ((*flags).bench != 0 && ft_strcmp(string, "--bench") == 0)
		return (0);
	else if ((*flags).strategy != 0 && (ft_strcmp(string, "--simple") == 0
		|| ft_strcmp(string, "--medium") == 0
		|| ft_strcmp(string, "--complex") == 0
		|| ft_strcmp(string, "--adaptive") == 0))
		return (0);
	return (1);
}

int main(void)
{
	t_flags	*flags;
	char str[] = "--simple 10 5 2 6";
	
	flags = parse_flags(str);
	printf("%d\n", (*flags).strategy);
	printf("%d\n", (*flags).bench);
	printf("%d\n", (*flags).start);
	return (0);
}

/*
static t_flags	*parse_flags(char **argv, t_flags *flags)
{
	//t_flags	*flags;
	int		i;
	
	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	(*flags).strategy = 0;
	(*flags).bench = 0;
	(*flags).start = 0;
	i = 1;
	
	while (argv[i] && !(is_valid_nbrs(argv[i])))
	{
		if (!is_validflag(argv[i]))
		{
			(*flags).start = -1;	
			return (flags);
		}
		flags = assign_flag(argv[i], flags);
		if ((*flags).start == -1)
			return (flags);
		i++;	
	}
	(*flags).start = i;
	return (flags);
}
*/