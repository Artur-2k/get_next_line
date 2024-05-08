#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>


# ifndef BUFFER_SIZE
#	define TRUE (1)
#	define BUFFER_SIZE (5)
# endif



int		ft_strlen(char *str);
char	*strjoin(char *s1, char *s2);
char	*strnjoin(char *s1, char *s2, unsigned int n);
int   check_for_newline(char *buffer);
char  *clear_buffer(char *buffer);
char	*get_next_line(int fd);

#endif