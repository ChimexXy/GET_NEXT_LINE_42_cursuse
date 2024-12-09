#include "get_next_line.h"

char	*read_str(int fd, char *str)
{
	char	*buff;
	int		readed;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	readed = 1;
	while (!new_line(str) && readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[readed] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}
int new_line(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return (0);
	while(str[i])
	{
		if(str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = read_str(fd, str);
	if (!str)
		return (NULL);
	ret = ft_first_line(str);
	str = ft_last_line(str);
	return (ret);
}
