#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
char *get_next_line(int fd);
char	*read_str(int fd, char *str);
int ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int new_line(char *str);
char	*ft_first_line(char *first_str);
char	*ft_last_line(char *last_str);

#endif



#endif