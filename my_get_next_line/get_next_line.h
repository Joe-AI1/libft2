#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct str_contain
{
    char            *str_buf;
    struct str_contain   *next;
}   t_contain;

int isnewline(t_contain *container);
void clear_malloc(t_contain **container, t_contain *c_contain);
int fill_line(t_contain *container, char *str);
void   append(t_contain **container, char *str);
void clear_container(t_contain **container);
char	*get_line(t_contain *container);
void build_container(t_contain **container, int fd);
char    *get_next_line(int fd);

#endif