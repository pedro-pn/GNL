# get_next_line (GNL)

My second project at 42 school.

## Description

get_next_line (GNL) is a function that reads and returns a line from a file descriptor. The line returned is allocated with [malloc(3)](https://man7.org/linux/man-pages/man3/malloc.3.html).

## The function

GNL uses the [read(2)](https://man7.org/linux/man-pages/man2/read.2.html) function to read BUFFER_SIZE bytes from a file descriptor. The standard BUFFER_SIZE is set to 42, but it can be altered at compilation (see [Compilation](#compilation)). The bytes read are stored in a static buffer allocated with [malloc(3)](https://man7.org/linux/man-pages/man3/malloc.3.html), helping GNL to keep track of the left over bytes.

The bonus version can read up to 257 file descriptors at the same time.

## USAGE

### Requirements

GNL requires gcc compiler and standard C libraries.

### Compilation

GNL is not a library, so you can compile it with your project cloning the files to your project folder.

	$> git clone https://github.com/pedro-pn/GNL
Include the GNL header to your projects files:

```c
#include "get_next_line.h"
```
Then compile it:

	$> gcc my_project.c get_next_line.c get_next_line_utils.c -I path/to/get_next_line.h

You can change the amount of bytes GNL reads for each [read(2)](https://man7.org/linux/man-pages/man2/read.2.html) call. To do so, compile it with `-D BUFFER_SIZE=n` flag, where `n` is the number of bytes to be read.

For bonus, add `_bonus.c` for each file and header names.

### Use

Call the function anytime you need to read a line from a file descriptor. Generic example below:
```c
#include <get_next_line.h>
#include <fcntl.h>

int main(void)
{
	int		fd;
	char	*line;

	fd = open("example.txt", O_RDONLY);
	line = get_next_line(fd);
	free(line);
	return (0);
}
```
Each call returns the next line.

## About

GNL is part of the [libft_complete](https://github.com/pedro-pn/libft_complete) library, which have all the useful functions that I made as part of the 42 curriculum to help me during the future projects.