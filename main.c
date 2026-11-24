#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
char *remember(void)
{
	static char *stash;
	char *word = "hello world";
	int i = 0;
	if (stash == NULL)
	{
		stash = malloc(6);
		if (!stash)
			return (NULL);
		while(i<5)
		{
			stash[i] = word[i];
			i++;
		}
		stash[5] = '\0';
	}
	return (stash);
}


int counter(void)
{
	static int count = 0;
	count++;
	return (count);	
}

int main()
{
	int fd ;
	char buffer[6];
	ssize_t ret ;
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		return (1);
	}
	while(1)
	{
		ret = read(fd, buffer,5);
		if (ret == -1)
		{
			close(fd);
			return(1);
		}else if (ret == 0)
		{
			break;
		}
		buffer[ret] = '\0';	
		printf("Bytes read :%zd\n",ret);
		printf("Buffer :%s\n\n", buffer);	
		printf("Counter :%d\n\n", counter());
	}
	char *rem = remember();
	if (rem)
		printf("Remember :%s| Adress :%p \n\n", rem,(void *)rem);
	char *rem1 = remember();
	if (rem1)
        	printf("Remember :%s| Adress :%p \n\n", rem1,(void *)rem1);
	free(rem);
	close(fd);
}
