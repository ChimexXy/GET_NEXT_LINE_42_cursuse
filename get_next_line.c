/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:11:11 by mozahnou          #+#    #+#             */
/*   Updated: 2024/12/14 13:55:49 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_read_string(int fd, char *ret)
{
	int		j;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	j = 1;
	while (j > 0)
	{
		j = read(fd, buffer, BUFFER_SIZE);
		buffer[j] = '\0';
		ret = ft_strjoin(ret, buffer);
		if (!ret)
		{
			free(ret);
			free(buffer); 
			return (NULL);
		}
		if (!ft_find_new_line(ret))
			break ;
	}
	free(buffer);
	return (ret);
}

char	*ft_ret_line(char *line)
{
	int	i;

	i = 0;
	if (!line || ft_strlen(line) == 0)
		return (NULL);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i++;
	return (ft_substr(line, 0, i));
}

char	*ft_remind_val(char *string)
{
	int		i;
	int		j;
	char	*ptr;

	if (!string)
		return (NULL);
	i = 0;
	j = 0;
	while (string[i] != '\n' && string[i] != '\0')
		i++;
	if (string[i] == '\n')
		i++;
	if (string[i] == '\0')
	{
		free(string);
		return (NULL);
	}
	ptr = malloc(ft_strlen(string) - i + 1);
	if (!ptr)
		return (NULL);
	while (string[i])
		ptr[j++] = string[i++];
	ptr[j] = '\0';
	free(string);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		free(string);
		string = NULL;
		return (NULL);
	}
	string = ft_read_string(fd, string);
	if (!string)
		return (NULL);
	line = ft_ret_line(string);
	string = ft_remind_val(string);
	return (line);
}
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd;
	int i = 0;
	fd = open("test.txt", O_RDONLY);
	
		char *str = get_next_line(3);
		printf("---> %s", str);
	close(fd);
    system("leaks -q a.out");
}
