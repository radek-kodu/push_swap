#include "../push_swap.h"

/*
Handles checking whether the numbers are acceptable.

* Calls atoi (long int)
* Check INT_MIN / INT_MAX boundaries
* Cast to int
* Detect duplicates
* Returns an array of ints

*/

int	**validate(char **array)
{
	int			i;
	long int	temp;

	while (array[i])
	{
		temp = atoi_plus(array[i]);
		// check INT_MIN / INT_MAX boundaries
		if (temp < INT_MIN || temp > INT_MAX)
			return (NULL);
		// cast to int
		array[i] = (int *)(temp);
		i++;
	}
	// detect duplicates
	if (find_duplicates(array))
		return (NULL);
	// return an array of ints
	return (array);
}
