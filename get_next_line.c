#include "get_next_line.h"

char *read_to_stash(int fd, char *stash)
{
	char *buffer;
	ssize_t ret;
	char *tmp;
	buffer = malloc(BUFFER_SIZE+1);
	if (!buffer)
	{
		free(stash);
		return (NULL);
	}
	while(!ft_strchr(stash,'\n'))
	{
		ret = read(fd,buffer,BUFFER_SIZE);
		if (ret == 0 || ret == -1)
		{
			if (ret == -1)
			{
				free(stash);
				free(buffer);
				return (NULL);
			}
			break;
		}
		buffer[ret] = '\0';
		tmp = ft_strjoin(stash,buffer);
		if (!tmp)
		{
                                free(stash);
                                free(buffer);
                                return (NULL);
		}
		free(stash);
		stash = tmp;
	}
	free(buffer);
	return(stash);
}

char *update_stash(char *stash)
{
    char    *new_stash;
    size_t  i;
    size_t  j;

    if (!stash)
        return (NULL);
    i = 0;
    while (stash[i] != '\0' && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    if (stash[i] == '\0')
    {
        free(stash);
        return (NULL);
    }
    new_stash = malloc(ft_strlen(stash) - i + 1);
    if (!new_stash)
    {
        free(stash);
        return (NULL);
    }
    j = 0;
    while (stash[i] != '\0')
    {
        new_stash[j] = stash[i];
        i++;
        j++;
    }
    new_stash[j] = '\0';
    free(stash);
    return (new_stash);
}

char *extract_line(char *stash)
{
	char *line;
	size_t i;
	size_t j;
	if (!stash || !*stash)
	{
		return (NULL);
	}
	i = 0;
	while (stash[i] != '\0' &&  stash[i] != '\n')
		i++;
	if (stash[i]=='\n')
		i++;
	line = malloc(i+1);
	if (!line)
		return (NULL);
	j = 0;	
	while(j<i)
	{
		line[j] = stash[j];
		j++;	
	}
	line[j] = '\0';
	return (line);
}



