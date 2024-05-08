#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *buffer ;
    char *new_line ;
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    new_line = (char *)malloc(sizeof(char));
    if (!buffer || !new_line)
        return (NULL);
    *new_line = '\0';
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0 || new_line)
    {
        buffer[bytes_read] = '\0';
        if (!check_for_newline(buffer))
            new_line = strjoin(new_line, buffer);
        else
        {
            new_line = strnjoin(new_line, buffer, check_for_newline(buffer) + 1);
            break;
        }
    }
    if (bytes_read == -1 || !new_line)
        free(new_line);
    return (new_line);
}
