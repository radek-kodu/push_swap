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
	long int	temp;
	t_node		stack;

	stack = list_init(stack);
	while (array[i])
	{
		temp = atoi_plus(array[i]);
		// check INT_MIN / INT_MAX boundaries
		if (temp < INT_MIN || temp > INT_MAX)
			return (NULL);
		// cast to int
		if (check_duplicates((int *)(temp), stack))
			return (NULL);
		else
			//add temp to stack
		i++;
	}
	free_array(array);
	// return the stack
	return (stack);
}
