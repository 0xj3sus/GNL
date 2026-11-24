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

char *ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
        	if (*str == (char)c)
		return ((char *)str);
		str++;
    	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

char *ft_strjoin(const char *s1, const char *s2)
{
	char *word;
	char *copy;
	size_t fslen;
	size_t sslen;
	fslen = ft_strlen(s1);
	sslen = ft_strlen(s2);
	word = malloc(fslen+sslen+1);
	if (!word)
		return (NULL);
	copy = word;
	while (s1 && *s1)
	{
		*word = *s1;
		word++;
		s1++;
	}
	while (s2 && *s2)
        {
                *word = *s2;
                word++;
                s2++;
        }
	*word = '\0';
	return (copy);
}
