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
	long    	temp_value;
	t_node		*stack;
	t_node		*new;

	temp_value = 0;
	i = 0;
	stack = NULL;
	while (array[i])
	{
		temp_value = ft_atoi(array[i]);
		if (temp_value < INT_MIN || temp_value > INT_MAX || is_duplicate((int)(temp_value), stack))
		{
			free_stack(stack); // create function            
			return (NULL);
		}
		new = new_node(temp_value);
		if (new == NULL)
			return (NULL);
		stack_add_back(&stack, new_node(temp_value));
		i++;
	}
	free_array(array);
	return (stack);
}

