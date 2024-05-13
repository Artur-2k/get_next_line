#include "get_next_line.h"

static char	*read_from_file(int fd, char *big_buffer);
static char *switch_pointers(char *big_buffer, char *small_buffer);
static char	*extract_line(char *buffer);
static char	*clear_buffer(char *big_buffer);

char	*get_next_line(int fd)
{
	char *line;	// line read
	static char	*big_buffer; //! STATIC VARIABLES ARE ALWAYS INNITIALIZED AS NULL

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1) //error check for fd, bufsize and read file
		return (NULL);
	if (!big_buffer)
		big_buffer = ft_strcalloc(1, sizeof(char)); // \0
	if (!ft_strchr(big_buffer, '\n'))
		big_buffer = read_from_file(fd, big_buffer);
	if (!big_buffer)	// read_from_file will allocate, if failed free the anterior buffer
		return (free(big_buffer), NULL);
	line = extract_line(big_buffer);
	big_buffer = clear_buffer(big_buffer);
	return (line);
}
char	*read_from_file(int fd, char *big_buffer)
{
	char *small_buffer;
	int bytes_read;

	small_buffer = (char *)ft_strcalloc((BUFFER_SIZE + 1), sizeof(char));
	if (!small_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, small_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(small_buffer), NULL);
		small_buffer[bytes_read] = '\0';
		big_buffer = switch_pointers(big_buffer, small_buffer);
		/* if (!big_buffer)
			return (free(small_buffer), NULL); */
		if (ft_strchr(big_buffer, '\n'))
			break ;
	}
	free(small_buffer);
	return (big_buffer);
}


char *switch_pointers(char *big_buffer, char *small_buffer)
{
	char *ptemp;

	ptemp = strjoin(big_buffer, small_buffer);
	if (!ptemp)
		return  (NULL);
	free(big_buffer);
	return (ptemp);
}
char	*extract_line(char *buffer)
{
	int			i;
	int			j;
	char		*line;

	if (!buffer || !*buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')// 123456N _._._._._.6.N.\0
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1 + 1)); // i + 1 chars + 1 for the null
	if (!line)
		return (line = NULL, NULL);
	line[i + 1] = '\0';
	line[i] = '\n';
	j = 0;
	while (j < i)
	{
		line [j] = buffer[j];
		j++;
	}
	return (line);
}
char	*clear_buffer(char *big_buffer)
{
	char *temp;
	int i;

	i = 0;
	while (big_buffer[i])
	{
		if (big_buffer[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	temp = ft_substr(big_buffer, i, ft_strlen(&big_buffer[i]));
	free(big_buffer);
	return (temp);
}

/*
static char	*clear_buffer(char *big_buffer)
{
    int  i;
    int	j;
	int	buf_len; // big buffer len

	buf_len = ft_strlen(big_buffer);
    i = 0;
    j = 0;
    while (i < buf_len) // do i still have bytes to see?
    {
		printf("%i: ", i);
		if (big_buffer[i] == '\n') // is the current char newline?
            break ;
		i++; // if it is start the shifting if possible
    }
    if (i < buf_len) // do i still have bytes to see?
    {
		i++;
        while (i < buf_len)// shitf the rightmost chars to the left(i) starting after the newline
		{
            big_buffer[j++] = big_buffer[i++];
		}
        while (j < buf_len) // set everything else after the shift to 0's
            big_buffer[j++] = 0;
    }
	else
	{
		big_buffer[0] = 0;
	}
    return (big_buffer); // return our cleared buffer
}
*/