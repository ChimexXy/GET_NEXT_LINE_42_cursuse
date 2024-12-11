#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char *get_next_line(int fd);
char	*r_string(int fd, char *str);
int ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int new_line(char *str);
char	*ft_first_line(char *first_str);
char	*ft_last_line(char *last_str);
char	*ft_strdup(char *s1);



#endif