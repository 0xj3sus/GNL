#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE  42
#endif

#ifndef MAX_SIZE
#define MAX_SIZE 100
#endif

char *get_next_line(int fd);
size_t ft_strlen(const char *str);
char *ft_strchr(const char *str, int c);
#endif

