*This project has been created as part of the 42 curriculum by sayala-c.*

## Description
The goal of this project is to program a function that returns a line read from a file descriptor. get_next_line allows reading the content of a text file line by line, which is highly efficient for processing files without loading them entirely into memory.

The algorithm logic follows these steps:

Reading: The get_content function reads from the file using a defined BUFFER_SIZE and concatenates the data into a static variable until a newline character (\n) or the end of the file is found.

Extraction: The get_line function analyzes the static variable to extract the current line, including the \n if it exists, to prepare it for return.

Updating: The get_update_content function cleans the static variable by removing the line that was just returned and preserving the "remainder" for the next call.
### Bonus
The bonus version of this project allows managing multiple file descriptors simultaneously. This is achieved by using an array of static pointers static char *content[10240], ensuring that the reading progress of one file is not lost when switching to another.

## Instructions
### Compilation
The project can be compiled with the -Wall -Wextra -Werror flags, including the definition of the buffer size:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

### Usage
To use this function in your projects, include the header in your C files and link the library during compilation:

#include "get_next_line.h"

#### AI Usage
* For this project AI has been used as a guide to understand concepts and logic and find errors. No code generation was used.

## Resources
* Man pages (read, malloc, free)
* 42 Cursus Guide - Get Next Line
* Documentation on static variables in C.


## Library Functions included in this project:

| Function | Description |
| :--- | :--- |
| `ft_printf` | Main entry point that parses the string and manages the `va_list`. |
| `ft_format` | Dispatcher that identifies the specifier and calls the corresponding function. |
| `ft_putnbr` | Handles %d and %i by processing signed integers. |
| `ft_putnbr_u` | Handles %u by processing unsigned decimal integers. |
| `ft_putnbr_hex` | Processes hexadecimal conversions for %x and %X. |
| `ft_p_print` | Specifically handles the %p conversion for memory addresses. |
| `ft_putchar` | Handles the %c and %% conversion by printing a single character. |
| `ft_putstr` | Handles the %s conversion by printing a string of characters. |

## Conversions implemented in this project:

| Convertion | Description |
| :--- | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a string of characters. |
| `%p` | Prints a pointer in hexadecimal format (0x...). |
| `%d` | Prints a decimal number (base 10). |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal number. |
| `%x` | Prints a hexadecimal number in lowercase. |
| `%X` | Prints a hexadecimal number in uppercase. |
| `%%` | Prints a percent sign. |
