# include "get_next_line.h"

#include <stdio.h>

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    char *line;
    
    int fd = open("test.txt", O_RDONLY);
    line = get_next_line(fd);
    while (line != NULL)
    {
        printf("%s", line);
        free(line); // freeing reseources for next line to be read
        line = get_next_line(fd);
    }
    close(fd);
    return (EXIT_SUCCESS);
}