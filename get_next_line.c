#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int ft_find_new_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return(0);
		i++;
	}
	return (1);
}


char *ft_read_string(int fd, char *ret)
{
    int     j;
    char    *buffer;
    char    *hold;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return NULL;
    while ((j = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[j] = '\0';
        hold = ft_strjoin(ret, buffer);
        if (!hold)
        {
            free(ret);
            free(buffer); 
            return NULL;
        }
        free(ret);
        ret = hold;
        if (!ft_find_new_line(ret))
            break;
    }
    free(buffer); 
    return ret;
}

char *ft_ret_line(char *line)
{
	int i;
	i = 0;
	if (!line || ft_strlen(line) == 0)
		return NULL;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i++;
	return (ft_substr(line, 0, i));
}


char *rest_func(char *string)
{
    int i = 0, j = 0;
    char *temp;

    if (!string)
        return NULL;
    while (string[i] != '\n' && string[i] != '\0')
        i++;
    if (string[i] == '\n')
        i++;
    if (string[i] == '\0')
    {
        free(string);
        return NULL;
    }
    temp = malloc(ft_strlen(string) - i + 1);
    if (!temp)
        return NULL;
    while (string[i])
        temp[j++] = string[i++];
    temp[j] = '\0';
    free(string);
    return temp;
}


char *get_next_line(int fd)
{
    static char *string;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    string = ft_read_string(fd, string);
    if (!string)
        return NULL;

    line = ft_ret_line(string);
    string = rest_func(string);
    return line;
}



int main()
{
	int fd;
	int f;
	char *str;

	fd = open("test.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf("%s", ft_read_string(fd)); 

	close(fd);
	system("leaks a.out");
}
