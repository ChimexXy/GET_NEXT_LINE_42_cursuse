#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;

	fd = open("tttt.txt", O_RDONLY);

	printf("%d", fd);
	close(fd);
}