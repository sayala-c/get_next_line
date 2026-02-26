#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include <stdlib.h>

char    *get_content(int fd, char *content);
char    *get_line(char *content);
char    *get_next_line(int fd);
char    *get_update_content(content);
size_t	ft_strlen(const char *s);

