*This project has been created as part of the 42 curriculum by sayala-c.*

## Description
The goal of this project is to program a function that returns a line read from a file descriptor. `get_next_line allows` reading the content of a text file line by line, which is highly efficient for processing files without loading them entirely into memory.

The algorithm logic follows these steps:

* Reading: The `get_content` function reads from the file using a defined BUFFER_SIZE and concatenates the data into a static variable until a newline character (\n) or the end of the file is found.

* Extraction: The `get_line` function analyzes the static variable to extract the current line, including the \n if it exists, to prepare it for return.

* Updating: The `get_update_content` function cleans the static variable by removing the line that was just returned and preserving the "remainder" for the next call.
### Bonus
The bonus version of this project allows managing multiple file descriptors simultaneously. This is achieved by using an array of static pointers static char *content[10240], ensuring that the reading progress of one file is not lost when switching to another.

## Instructions
### Compilation
The project can be compiled with `cc` and  the `-Wall -Wextra -Werror` flags, including the definition of the `buffer size`:

`cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c`

### Usage
To use this function in your projects, include the header in your C files and link the library during compilation:

`#include "get_next_line.h"`

#### AI Usage
For this project AI has been used as a guide to understand concepts and logic and find errors. No code generation was used.

## Resources
* Man pages (read, malloc, free)
* 42 Cursus Guide - Get Next Line
* Documentation on static variables in C.


## Library Functions included in this project:

| Function | Description |
| :--- | :--- |
| `get_next_line` | Main entry point that coordinates reading, extraction, and updating. |
| `get_content` | Reads from the FD and accumulates data into the static buffer. |
| `get_line` | Extracts the complete line up to the \n from the accumulated string. |
| `get_update_content` | Trims the static variable to keep only the unread data. |
| `gnl_strjoin` | Concatenates two strings while correctly managing memory. |
| `ft_strchr` | Locates the \n character within a string. |
| `ft_strlen` | Calculates the length of a character string. |
| `dup_gnl` | Helper used to copy characters from the buffer to the final line. |

