#include "get_next_line.h"

char	*r_string(int fd, char *str)
{
	char	*ptr;
	int		i;

	ptr = malloc(BUFFER_SIZE + 1);
	if (!ptr)
		return (NULL);
	i = 1;
	while (!new_line(str) && i != 0)
	{
		i = read(fd, ptr, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			free(ptr);
			return (NULL);
		}
		ptr[i] = '\0';
		str = ft_strjoin(str, ptr);
	}
	free(ptr);
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
	str = r_string(fd, str);
	if (!str)
		return (NULL);
	ret = ft_first_line(str);
	str = ft_last_line(str);
	return (ret);
}
