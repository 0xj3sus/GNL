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
