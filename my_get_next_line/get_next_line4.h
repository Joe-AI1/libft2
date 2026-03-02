#ifndef GET_NEXT_LINE4_H
# define GET_NEXT_LINE4_H

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
size_t stash_len(t_contain *stash);
int isnewline(t_contain *stash);
t_contain *new_node(char *buffer, int read_status);
void free_stash(t_contain **stash);
t_contain *clear_stash(t_contain *stash, char *line);
static int copy_node(t_contain *node, char *line, size_t i);
char *extract_line(t_contain *stash);
t_contain *append_node(t_contain *stash, t_contain *node);
t_contain	*collect_stash(t_contain *stash, int fd);
char    *get_next_line(int fd);

#endif