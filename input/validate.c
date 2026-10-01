#include "../push_swap.h"

/*
Handles checking whether the numbers are acceptable.

* Calls atoi (long int)
* Check INT_MIN / INT_MAX boundaries
* Cast to int
* Detect duplicates
* Returns a stack of ints

*/

t_node	*validate(char **array)
{
	int			i;
	long    	temp;
	t_node		*stack;

	temp = 0;
	i = 0;
	stack = NULL;
	while (array[i])
	{
		temp = ft_atoi(array[i]);
		if (temp < INT_MIN || temp > INT_MAX)
			return (NULL);
		if (is_duplicate((int)(temp), stack))
		{
			free(stack);            
			return (NULL);
		}
		stack_add_back(stack, new_node(temp));
		i++;
	}
	free_array(array);
	return (stack);
}

