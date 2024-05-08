#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return i;
}

char	*strjoin(char *s1, char *s2)
{
	char	*nstr;
	size_t	i;

	nstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!nstr)
		return (NULL);
	//ft_strcpy(nstr, s1);
	i = 0;
	while (*s1)
		nstr[i++] = *(s1++);
	//ft_strcat(nstr, s2);
	while (*s2)
		nstr[i++] = *(s2++);
	nstr[i] = 0;
	return (nstr);
}

char	*strnjoin(char *s1, char *s2, unsigned int n)
{
	char	*nstr;
	size_t	i;

	nstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + n + 1));
	if (!nstr)
		return (NULL);
	//ft_strcpy(nstr, s1);
	i = 0;
	while (*s1)
		nstr[i++] = *(s1++);
	//ft_strcat(nstr, s2);
	while (*s2 && n-- > 0)
		nstr[i++] = *(s2++);
	nstr[i] = 0;
	return (nstr);
}


int   check_for_newline(char *buffer)
{
	int	i;

	i = 0;
    if (!buffer)
        return (0);
    while (buffer[i])
    {
        if (buffer[i] == '\n')
            return (i + 1);
        i++;
    }
    return (0);
}

char  *clear_buffer(char *buffer)
{
    int    i;
    int    j;

    i = 0;
    j = 0;
    while (i < BUFFER_SIZE)
    {
        if (buffer[i] == '\n')
            break ;
        i++;
    }
    if (i < BUFFER_SIZE)
    {
        i++;
        while (i < BUFFER_SIZE)
            buffer[j++] = buffer[i++];
        while (j < BUFFER_SIZE)
            buffer[j++] = 0;
    }
    return (buffer);
}
