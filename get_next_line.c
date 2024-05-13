#include "get_next_line.h"

static char	*read_from_file(int fd, char *big_buffer);
static char *append_buffers(char *big_buffer, char *small_buffer);
static char	*extract_line(char *buffer);
static char	*clear_buffer(char *big_buffer);

char	*get_next_line(int fd)
{
	char *line;	// line read
	static char	*big_buffer; //! STATIC VARIABLES ARE ALWAYS INNITIALIZED AS NULL

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1) //error check for fd, bufsize and read file
		return (NULL);
	if (!big_buffer) // if i dont have a big buffer (1st time called)
		big_buffer = ft_strcalloc(1, sizeof(char)); // create one of size 1 and fill it with '0's
	if (!ft_strchr(big_buffer, '\n')) // if there isnt a newline
		big_buffer = read_from_file(fd, big_buffer); // read from the file
	if (!big_buffer)	// read_from_file will allocate, if failed free the anterior buffer
		return (free(big_buffer), NULL);
	line = extract_line(big_buffer); // we will extract the line until de \n or '0' if not a \n in the buffer
	big_buffer = clear_buffer(big_buffer); // then we will remove all that comes before the newline
	return (line); // we deliver the next line
}
char	*read_from_file(int fd, char *big_buffer)
{
	char *small_buffer;
	int bytes_read;

	small_buffer = (char *)ft_strcalloc((BUFFER_SIZE + 1), sizeof(char)); // we will read buffer size bytes per call and add it to the big buffer
	if (!small_buffer) //error check
		return (NULL);
	bytes_read = 1; // if no error we read at least 1 byte
	while (bytes_read > 0) // while we read any bytes
	{
		bytes_read = read(fd, small_buffer, BUFFER_SIZE); // read to the small buffer fd BUFFER_SIZE bytes
		if (bytes_read == -1) // if error free the allocated memory and return NULL
			return (free(small_buffer), NULL);
		small_buffer[bytes_read] = '\0'; // we read BUFFER_SIZE bytes and we need to null terminate the new buffer
		big_buffer = append_buffers(big_buffer, small_buffer); // we will append the small buffer to the big one
		//! CHECK IF NEEDED TO BE PROTECTED OR IF IT IS ALREADY PROTECTED
		if (ft_strchr(big_buffer, '\n')) // if we fetched a newline we stop reading
			break ;
	}
	free(small_buffer); // we free the small buffer
	return (big_buffer); // and return the big one
}


char *append_buffers(char *big_buffer, char *small_buffer)
{
	char *new_big_buffer;

	new_big_buffer = strjoin(big_buffer, small_buffer); // we're joining the 2 together
	if (!new_big_buffer) // error check
		return  (NULL);
	free(big_buffer); // free the old buffer
	return (new_big_buffer); // update the big buffer
}
char	*extract_line(char *buffer)
{
	int			i;
	int			j;
	char		*line;

	if (!buffer || !*buffer) // invalid buffer check
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n') // skip the caracters until we find a newline or a \0
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1 + 1)); // (i + 1) chars + 1 for the null
	if (!line) // error check
		return (line = NULL, NULL);
	line[i + 1] = '\0'; // null terminate it
	j = 0;
	while (j <= i) // while i didnt copy all the indexed chars from buffer to line copy
	{
		line [j] = buffer[j];
		j++;
	}
	return (line); // return the line
}
char	*clear_buffer(char *big_buffer)
{
	char *cleaned_big_buffer;
	int i;

	i = 0;
	while (big_buffer[i]) // while i iterate the string
	{
		if (big_buffer[i] == '\n') // if i find a newline
		{
			i++;
			break; // i exit
		}
		i++;
	}
	cleaned_big_buffer = ft_substr(big_buffer, i, ft_strlen(&big_buffer[i])); // we then create a substring starting from the char after the newline or at the '0' until the end of the string to remove any read chars
	free(big_buffer); // free the old buffer
	return (cleaned_big_buffer); // update the new cleaned one
}
