/*
Accepts an array of numbers in char type. 
Handles checking whether the numbers are acceptable.

* Calls atoi (long int)
* Check INT_MIN / INT_MAX boundaries
* Cast to int
* Detect duplicates
* Returns an array of ints

*/
#include "../push_swap.h"

static int  is_duplicate_nbrs(int number, int *numbers, int size);

int	*validate(char **array, int total_elements)
{
	int		i;
	long    temp_value;
    int     *numbers;    

    numbers = malloc(total_elements * sizeof(int));
    if (!numbers)
        return (free_array(array), NULL);
    i = 0;
    while (i < total_elements)
    {
        if (!ft_atoi(array[i], &temp_value))
            return (free(numbers), free_array(array), NULL);
        if (temp_value < INT_MIN || temp_value > INT_MAX || is_duplicate_nbrs((int)temp_value, numbers, i))
            return (free(numbers), free_array(array), NULL);
        numbers[i] = (int)temp_value;
        i++;
    }
	free_array(array);
	return (numbers);
}

static int  is_duplicate_nbrs(int number, int *numbers, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (numbers[i] == number)
            return (1);
        i++;
    }
    return (0);
}
