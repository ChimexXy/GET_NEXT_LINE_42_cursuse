#include "get_next_line.h"
#include <stdio.h>

int main() {
    int fd;
    char *line;

    fd = open("tt.txt", O_RDONLY);

    printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));


    close(fd);
    return 0;
}
