#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*				   
 *-----------------
 *-----INCLUDES----
 *-----------------
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
 *-----------------
 *---PROTOTYPES----
 *-----------------
*/

char	*get_next_line(int fd);

// UTILS

size_t	ft_strlen(const char *s);
int		ft_strchr(const char *s, int c);
char	*strjoin(char *s1, char *s2);
char    *ft_strcalloc(size_t nitems, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif

/*
 *-----------------
 *---BUFFER_SIZE---
 *-----------------
*/

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE (5)
# endif