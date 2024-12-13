#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10

#endif

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

char *get_next_line(int fd);
int ft_strlen(char *str);
char *ft_strdup(char *s);
char *ft_strjoin(char *s1, char *s2);
char *ft_substr(char *string, int start, int len);
int ft_find_new_line(char *str);
char *ft_read_string(int fd, char *ret);
char *ft_ret_line(char *line);
char *ft_remind_val(char *string);


#endif