#include "../push_swap.h"

/*
Handles checking whether the numbers are acceptable.

* Calls atoi (long int)
* Check INT_MIN / INT_MAX boundaries
* Cast to int
* Detect duplicates
* Returns an array of ints

*/

t_node	validate(char **array)
{
	int			i;
	long    	temp;
	t_node		stack;

    stack = create_stack();
    i = 0;
	while (array[i])
	{
		temp = ft_atoi(array[i]);
		// check INT_MIN / INT_MAX boundaries
		if (temp < INT_MIN || temp > INT_MAX)
			return (NULL);
		// cast to int
		if (is_duplicate((int *)(temp), stack))
		{
            free_stack(stack);            
            return (NULL);
        }
		//add_node(stack, temp)
		i++;
	}
	free_array(array);
	// return the stack
	return (stack);
}
