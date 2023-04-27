# Get Next Line (GNL)

Get Next Line is a C project designed to read lines of text from a file descriptor without knowing the size of the lines beforehand. This project is particularly useful for applications that require reading large files with varying line lengths. GNL is created as part of the 42 coding school curriculum.

## Features

- Read lines from a file descriptor.
- Handles lines of varying length.
- Efficient memory management.
- Bonus feature: Can read from multiple file descriptors simultaneously.

## Getting Started

### Prerequisites

- A Unix-based operating system (macOS, Linux, or WSL on Windows)
- GCC compiler
- `make` utility

### Installation

1. Clone the repository:
```
git clone https://github.com/JosephKiragu/get_next_line.git
```

2. Change into the project directory:
```
cd get_next_line
```

3. Compile the project using the provided `Makefile`:
```
make
```

### Usage

1. Include the header file `get_next_line.h` in your C source files where you want to use the GNL function.

```c
#include "get_next_line.h"
```

2. Use the `get_next_line` function to read lines from a file descriptor. Here's an example of how to read lines from a file:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
```

3. Compile your program with the GNL object files:

```
gcc -Wall -Wextra -Werror -I./ -o your_program your_program.c get_next_line.o get_next_line_utils.o
```

4. Run your program:

```
./your_program your_text_file.txt
```

