#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int main(void)
{
	int fd;

	fd = open("teste.txt", O_RDONLY);
	if (!fd)
		return 1;
	//get_next_line(fd)

	for(int i = 0; i < 3; i++)
	{
		printf("%s", get_next_line(fd));
	}

	close(fd);
    return 0;
}