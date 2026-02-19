#ifdef MY_GET_NEXT_LINE_H
# define MY_GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct str_list
{
    char            *str_buf;
    struct str_list   *next_list;
}   tmp_list;
