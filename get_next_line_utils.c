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

	if (!s1)
		return NULL;
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

char	*ft_first_line(char *str1)
{
	int		i;
	char	*str;

	i = 0;
	if (!str1[i])
		return (NULL);
	while (str1[i] && str1[i] != '\n')
		i++;
	if (str1[i] == '\n')
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (str1[++i] && str1[i] != '\n')
		str[i] = str1[i]; 
	if (str1[i] == '\n')
	{
		str[i] = str1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_last_line(char *str2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str2[i] && str2[i] != '\n')
		i++;
	if (!str2[i])
	{
		free(str2);
		return (NULL);
	}
	if (str2[i] == '\n')
		i++;
	str = malloc((ft_strlen(str2) - i) + 1);
	if (!str)
		return (NULL);
	while (str2[i])
		str[j++] = str2[i++];
	str[j] = '\0';
	free(str2);
	return (str);
}