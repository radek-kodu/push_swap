*This project has been created as part of the 42 curriculum by rpokorny, jrosette.*

# Push swap

The Push swap project is a "VERY SIMPLE and highly STRAIGHTFORWARD" algorithm project:
data must be sorted.

Just sort integer values using two stacks and wirtting down each of operation used, nothing complicated right?

## Description

### Input

### Operations

Sorting is done via predefined operations:

sa (swap a): Swap the first two elements at the top of stack a.
	Do nothing if there is only one or no elements.

sb (swap b): Swap the first two elements at the top of stack b.
	Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by one.
	The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by one.
	The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by one.
	The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by one.
	The last element becomes the first one.

rrr : rra and rrb at the same time.

And they are consolidated into 4 files based on it's function.

In the prcess also prints down each name of the operation used and counts every usage.

### Algorithms

For sorting the numbers there are 3 sorting algorithms, a few sorting functions for small stacks and helper functions for algorithms.

Of course, every algorithm had to be alternated for two-stack manipulation.

#### Small

If there is a input including less then 6 numbers, we have special sorting functions for each of the cases.

#### Simple

Selection sort

#### Medium

Chunk-based sort

#### Complex

Binary radix sort

#### Adaptive

Based on the disorder calculated at the beginning of the project, this function chooses the right algorithm to use. The higher the disorder, the more complecated and effective sorting algorithm.

### Others

Indexing - for each of the numbers creates index based on its value in comparison of other numbers.

Disorder - calculates disorder of the numbers. If it's zero, the stack is already sorted, and the maximum value is 1.


## Instructions

Beside the numbers you can also costumise the way the numbers are sorted via 4 different flags:

--simple Forces the use of your O(n2) algorithm.
--medium Forces the use of your O(n√n) algorithm.
--complex Forces the use of your O(n log n) algorithm.
--adaptive Forces the use of your adaptive algorithm based on disorder.
		This is the default behavior if no selector is given.

In addition, there is one more flag, --bench.

The optional benchmark mode display, after sorting:
◦ The computed disorder (% with two decimals).
◦ The name of the strategy used and its theoretical complexity class.
◦ The total number of operations.
◦ The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb,
rrr).

The benchmark output will be sent to stderr and only appear when the flag is
present.

## Resources

https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81
https://deepwiki.com/nach131/push_swap/4.3-chunk-based-sorting
https://leofu890806.medium.com/push-swap-tutorial-fa746e6aba1e
