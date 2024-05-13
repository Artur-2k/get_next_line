#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
int main() {
    int fd = open("teste4.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}

/* #include <stdio.h>
#include "get_next_line.h"


int main() {
    char *s = "Hello, world!";
    unsigned int start = 14;
    size_t len = 6;

    char *substring = ft_substr(s, start, len);
    if (substring == NULL) {
        printf("Failed to allocate memory for substring\n");
        return 1;
    }

    printf("Substring: %s\n", substring);

    free(substring);
    return 0;
} */