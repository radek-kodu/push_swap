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

## Available operations

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
