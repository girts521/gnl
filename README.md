# get_next_line

## Description

`get_next_line` is a function that allows you to read a file line by line. It handles any file descriptor and reads the next line each time it's called, making it suitable for processing text files or input streams where data needs to be parsed one line at a time.

## Features

- Reads from any file descriptor, including:
  - Files
  - Standard input (stdin)
  - Pipes

- Returns one line at a time, without including the newline character.

## Usage

1. Include the header in your source code:
    ```c
    #include "get_next_line.h"
    ```

2. Use the `get_next_line` function to read lines from a file:
    ```c
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while (get_next_line(fd, &line) > 0) {
        // Do something with the line
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    ```

## Installation

Clone this repository and compile the source files along with your project:

```bash
git clone https://github.com/yourusername/get_next_line.git
cd get_next_line
make
```
## License

This project is distributed under the MIT License. See the LICENSE file for details.

## Contact
If you have any questions or feedback, feel free to create an issue on this repository.
