#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    char *stash;

    fd = open("text.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    stash = read_to_stash(fd, NULL);
    if (stash)
        printf("Stash: [%s]\n", stash);
    else
        printf("Stash: NULL\n");
    free(stash);
    close(fd);
    return (0);
}
