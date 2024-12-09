#include "get_next_line.h"

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	m;
	char	*ptr;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = 0;
	j = 0;
	m = 0;
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i])
		ptr[m++] = s1[i++];
	while (s2[j])
		ptr[m++] = s2[j++];
	ptr[m] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_first_line(char *first_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!first_str[i])
		return (NULL);
	while (first_str[i] && first_str[i] != '\n')
		i++;
	if (first_str[i] == '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (first_str[++i] && first_str[i] != '\n')
		str[i] = first_str[i];
	if (first_str[i] == '\n')
	{
		str[i] = first_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_last_line(char *last_str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (last_str[i] && last_str[i] != '\n')
		i++;
	if (!last_str[i])
	{
		free(last_str);
		return (NULL);
	}
	if (last_str[i] == '\n')
		i++;
	new_str = malloc((ft_strlen(last_str) - i) + 1);
	if (!new_str)
		return (NULL);
	while (last_str[i])
		new_str[j++] = last_str[i++];
	new_str[j] = '\0';
	free(last_str);
	return (new_str);
}