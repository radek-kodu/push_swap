# Parsing Overview

## Functions

| Function | What it does | Return value | What it modifies |
|---|---|---|---|
| `convert_input()` | Combines all command-line arguments into one string. | `char *` (string) | Allocates a new string; does not modify `argv`. |
| `parse_flags()` | Extracts and validates flags, assigns their settings, and records where the numbers begin. | `t_flags *` (struct) | Allocates and modifies the `t_flags` structure. |
| `parse_nbrs()` | Skips the flags, validates the numeric input format, counts the numbers, and extracts them into separate strings. Converts numeric strings into integers and checks for conversion errors, integer-range violations, and duplicates. | `int *` (array of ints) | Allocates the integer array and frees the input string array. |


## Memory ownership

| Allocated memory | Allocated by | Freed by |
|---|---|---|
| `input` (`char *`) | `convert_input()` | `main()` |
| `flags` (`t_flags *`) | `parse_flags()` | `main()` |
| `array` (`char **`) and its strings | `parse_nbrs()` | `validate()` |
| `numbers` (`int *`) | `validate()` | `main()` |

## Call flow

```text
                         main(argc, argv)
                                |
                                v
                    +-------------------------+
                    |      convert_input()    |
                    +-------------------------+
                    | Accepts:                |
                    | - argc                  |
                    | - argv                  |
                    |                         |
                    | Does:                   |
                    | - Calculates total      |
                    |   length of arguments   |
                    | - Allocates one string  |
                    | - Joins argv[1] onward  |
                    |   into a single string  |
                    | - Separates arguments   |
                    |   with spaces           |
                    |                         |
                    | Returns: char *input    |
                    +-------------------------+
                                |
                                v
                    +-------------------------+
                    |       parse_flags()     |
                    +-------------------------+
                    | Accepts:                |
                    | - input                 |
                    |                         |
                    | Does:                   |
                    | - Allocates t_flags     |
                    | - Extracts flags from   |
                    |   the beginning of input|
                    | - Checks whether flags  |
                    |   are valid and whether |
                    |   they are duplicated   |
                    | - Sets bench and        |
                    |   strategy fields       |
                    | - Records the position  |
                    |   where numbers begin   |
                    |                         |
                    | Returns: t_flags *flags |
                    +-------------------------+
                                |
                                v
                    +--------------------------+
                    |       parse_nbrs()       |
                    +--------------------------+
                    | Accepts:                 |
                    | - input                  |
                    | - flags->start           |
                    | - &total_elements        |
                    |                          |
                    | Does:                    |
                    | - Skips the flags        |
                    | - Validates the numeric  |
                    |   input format           |
                    | - Counts the numbers     |
                    | - Allocates a char **    |
                    |   array                  |
                    | - Extracts each number   |
                    |   into its own string    |
                    | - Updates total_elements |
                    | - calls validate()       |
					|	Does:				   |
                    | - Allocates an int array |
                    | - Converts each numeric  |
                    |   string into a long     |
                    | - Checks LONG overflow   |
                    | - Checks INT_MIN /       |
                    |   INT_MAX boundaries     |
                    | - Checks for duplicates  |
                    | - Casts valid values to  |
                    |   int and stores them    |
                    | - Frees the char **array |
                    |   and its strings        |
                    |                          |
                    | Returns: int *numbers    |
                    +--------------------------+
                                |
                                v
                    +-------------------------+
                    |       Continue in       |
                    |          main()         |
                    +-------------------------+
                    | - Uses numbers to       |
                    |   initialize the stacks |
                    | - Executes push_swap    |
                    | - Frees allocated data  |
                    +-------------------------+
```
