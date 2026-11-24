#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
	size_t i ;
	i= 0;
	if (!str)
		return (0);
	while(*str)
	{
		str++;
		i++;	
	}
	return (i);
}
