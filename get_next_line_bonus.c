/* ************************************************************************************************ */
/*                                                                                                  */
/*                                                        :::   ::::::::   ::::::::  :::::::::::    */
/*   get_next_line_bonus.c                             :+:+:  :+:    :+: :+:    :+: :+:     :+:     */
/*                                                      +:+         +:+        +:+        +:+       */
/*   By: mozahnou <mozahnou@student.1337.ma>           +#+      +#++:      +#++:        +#+         */
/*                                                    +#+         +#+        +#+      +#+           */
/*   Created: 2024/12/13 17:32:56 by mozahnou        #+#  #+#    #+# #+#    #+#     #+#             */
/*   Updated: 2024/12/13 17:32:56 by mozahnou     ####### ########   ########      ###.ma           */
/*                                                                                                  */
/* ************************************************************************************************ */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int ft_find_new_line(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
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

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return NULL;
    while ((j = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[j] = '\0';
        ret = ft_strjoin(ret, buffer);
        if (!ret)
        {
            free(ret);
            free(buffer); 
            return NULL;
        }
        if (!ft_find_new_line(ret))
            break;
    }
    free(buffer);
    return (ret);
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


char *ft_remind_val(char *string)
{
    int i;
    int j;
    char *ptr;

    if (!string)
        return NULL;
	i = 0;
	j = 0;
    while (string[i] != '\n' && string[i] != '\0')
        i++;
    if (string[i] == '\n')
        i++;
    if (string[i] == '\0')
		return (free(string), NULL);
    ptr = malloc(ft_strlen(string) - i + 1);
    if (!ptr)
		return (NULL);
    while (string[i])
        ptr[j++] = string[i++];
    ptr[j] = '\0';
	free(string);
	return (ptr);
}
#include <limits.h>
char *get_next_line(int fd)
{
    static char *string[OPEN_MAX];
    char *line;

    if (fd < 0)
        return (NULL);
    if (BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
    {
        free(string[fd]);
        string[fd] = NULL;
        return (NULL);
    }
    string[fd] = ft_read_string(fd, string[fd]);

    if (!string[fd])
        return NULL;
    line = ft_ret_line(string[fd]);	
    string[fd] = ft_remind_val(string[fd]);
    return (line);
}



// int main()
// {
// 	int fd1;
// 	int fd2;
// 	int fd3;
// 	int fd4;
// 	int f;
// 	char *str;

// 	fd1 = open("test.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);

// 	printf("---> %s", get_next_line(-1));
// 	// printf("---> %s", get_next_line(3));
// 	// printf("---> %s", get_next_line(4));
// 	// printf("---> %s", get_next_line(3));
// 	// printf("---> %s", get_next_line(4));

//     // system("leaks -q a.out");
// 	// close(fd1);
// }
