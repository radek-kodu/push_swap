#include "../push_swap.h"

/*
Handles checking whether the numbers are acceptable.

* Calls atoi (long int)
* Check INT_MIN / INT_MAX boundaries
* Cast to int
* Detect duplicates
* Returns an array of ints

*/

t_node	*validate(char **array)
{
	int			i;
	long    	temp;
	t_node		*stack;

    temp = 0;
    i = 0;
    stack = new_node(temp);
    if (!stack)
        return (NULL);
	while (array[i])
	{
		temp = ft_atoi(array[i]);
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
