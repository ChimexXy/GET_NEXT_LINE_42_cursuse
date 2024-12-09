#include "get_next_line.h"
#include <stdio.h>

int main() {
    int fd;
    char *line;

    fd = open("tt.txt", O_RDONLY);
   
    while ((line = get_next_line(fd)) > 0) 
	{
        printf("%s\n", line);
    }

    close(fd);
    return 0;
}
