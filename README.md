*This project has been created as part of the 42 curriculum by rpokorny, jrosette.*

# push_swap

## Description

**push_swap** is an algorithmic sorting project from the 42 curriculum. The goal is to sort a list of integers in ascending order using two stacks (`a` and `b`) and a limited set of stack operations, while minimizing the total number of operations.

The program receives a list of integers as arguments, assigns each number an index based on its relative value, and sorts the numbers using a selected sorting strategy.

The project focuses on:
- Understanding and implementing sorting algorithms.
- Working with stacks and linked lists.
- Managing memory allocation and deallocation.
- Handling input parsing and validation.
- Optimizing the number of operations required to sort a list.

## Instructions

### Compilation

Clone the repository and navigate to its root directory:

```bash
git clone <repository-url>
cd push_swap
```

Compile the project using the Makefile:

```bash
make
```

This generates the `push_swap` executable.

Other available Makefile commands:

```bash
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Recompile the project
```

### Execution

Run the program by passing a list of integers:

```bash
./push_swap 4 67 3 87 23
```

The program outputs the stack operations required to sort the numbers in ascending order.

You can also provide the numbers as a quoted string:

```bash
./push_swap "4 67 3 87 23"
```

### Sorting strategies

The program supports the following optional strategy flags:

| Flag | Description |
|---|---|
| `--adaptive` | Selects the adaptive sorting strategy. |
| `--simple` | Selects the simple sorting strategy. |
| `--medium` | Selects the medium sorting strategy. |
| `--complex` | Selects the complex sorting strategy. |
| `--bench` | Enables benchmark mode. |

Example:

```bash
./push_swap --adaptive 4 67 3 87 23
```

Benchmark mode can be combined with one sorting strategy:

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

Only one sorting strategy can be selected at a time. Flags must appear before the integer arguments.

### Checking the output

If a compatible `checker` executable is available, you can verify whether the generated operations correctly sort the input:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```

A successful sort should return:

```text
OK
```

### Available operations

The program sorts the integers using the following operations:

| Operation | Description |
|---|---|
| `sa` | Swap the first two elements of stack A. |
| `sb` | Swap the first two elements of stack B. |
| `ss` | Perform `sa` and `sb` simultaneously. |
| `pa` | Push the top element of stack B onto stack A. |
| `pb` | Push the top element of stack A onto stack B. |
| `ra` | Rotate stack A upwards. |
| `rb` | Rotate stack B upwards. |
| `rr` | Perform `ra` and `rb` simultaneously. |
| `rra` | Reverse rotate stack A. |
| `rrb` | Reverse rotate stack B. |
| `rrr` | Perform `rra` and `rrb` simultaneously. |

### Algorithms Used

| Strategy | Description of Algorithm Used |
|---|---|
| `small` | The sorting for 2-3 numbers is manually solved as there are limited combinations, making the solutions straightforward. For 4-5 numbers, the smallest number/s are moved to stack B, until there are 3 numbers left in stack A, which are then sorted. Afterwards, the numbers in B are returned to A. |
| `simple` | `Selection sort` was utilized as it allows us to build on existing algorithms from `--small`. It finds the smallest numbers, moves them to the top of the stack A, and pushes them to stack B. When there are only three numbers left in A, the algorithms in `--small` are used to sort the remaining numbers. |
| `medium` | `Chunk sorting` was utilized as it follows the existing logic present in `selection sort`. Instead of using the actual values, the numbers are indexed and the indices are used as basis for sorting. First, it divides the stack into chunks of 6 or 10. Then it rotates through the entire stack A, pushing to B the indices that belong to the first chunk. After, it moves to the second chunk, and so on until everything has been moved to B. It then finds out the position of the largest index in B, and based on its position, rotates or reverse rotates the stack so that the number emerges at the top and is pushed back to A. |
| `complex` | `Binary radix sorting` was utilized in order to make use of the indexing function utilized in `chunk sorting`.  Instead of using the actual values, the numbers are indexed and the indices are used as basis for sorting. First, it calculates the maximum number of bits needed to represent the largest index. It then iterates through each bit position, starting with the least significant bit (rightmost). For each bit, it goes through all elements in stack A, checking whether the current bit is 0 or 1. If it is 0, the element is pushed to stack B using pb(); if it is 1, the element is rotated to the bottom of stack A using ra(). Once all elements have been checked for that bit, it pushes everything from B back to A using pa(). It then moves to the next bit position and repeats the process until all bits have been examined, resulting in the elements being sorted in ascending index order. |
| `adaptive` | Based on calculated disorder, the numbers are sorted with simple, medium, or complex strategies. The `adaptive` strategy is the default strategy. If disorder is less than 0.2, a simple strategy is used. If between 0.2 (inclusive) and 0.5 (exclusive), a medium strategy is used. For 0.5 (inclusive) and beyond, a complex strategy is employed. |

### Learners' Contributions

| Learner | Contribution |
|---|---|
| `jrosette` | Operations (push, rotate, reverse rotate, swap), Input (parsing and validation of user input), Data structure (flags, nodes), Input utils, Stack utils, Small and Simple algorithm, README file, Debugging. |
| `rpokorny` | Data structure (data, bench) and data utils, Refactoring of Operations (push, rotate, reverse rotate, swap), Indexing, Medium and Complex algorithm, Bench, Printing of operations and bench, Makefile, Debugging |

## Resources

- https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81
- https://deepwiki.com/nach131/push_swap/4.3-chunk-based-sorting
- https://leofu890806.medium.com/push-swap-tutorial-fa746e6aba1e


### AI usage

AI tools (ChatGPT) were used as supplementary learning and debugging resources throughout the project.

Specifically, AI assistance was used for:
- **Conceptual explanations:** Understanding sorting algorithms, binary representation, bitwise operations, stacks, pointers, and memory management.
- **Algorithm analysis:** Breaking down sorting strategies into smaller steps and understanding how and why they work.
- **Debugging:** Investigating compilation errors, segmentation faults, memory leaks, input parsing issues, and unexpected program behavior.
- **Code review:** Discussing function responsibilities, pointer handling, code organization, and possible improvements.
- **Documentation:** Assisting with the preparation and organization of this README.

AI was primarily used to support understanding, troubleshoot problems, and evaluate implementation choices rather than as a substitute for learning the underlying concepts.
