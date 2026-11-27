#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    char *stash;

    stash = ft_strjoin(NULL, "ABC\nDEF");
    stash = update_stash(stash);
    if (stash)
        printf("New stash: [%s]\n", stash);
    else
        printf("New stash: NULL\n");
    free(stash);
    return (0);
}
