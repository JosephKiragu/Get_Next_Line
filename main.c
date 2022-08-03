# include "get_next_line.h"

#include <stdio.h>

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    char *line;
    char *line1;

    int fd = open("test.txt", O_RDONLY);
    line = get_next_line(fd);
    int fd2 = open("test_1.txt", O_RDONLY);
    line1 = get_next_line(fd2);
    while (line != NULL && line1 != NULL)
    {
        printf("%s", line);
        printf("%s", line1);
        free(line); // freeing reseources for next line to be read
        free(line1); 
        line = get_next_line(fd);
        line1 = get_next_line(fd2);

    }
    close(fd);
    close(fd2);
    return (EXIT_SUCCESS);
}