/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_getnextline_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:20:21 by joe               #+#    #+#             */
/*   Updated: 2026/02/19 08:32:31 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

int ft_isnewline(tmp_list *container)
{
    int i;

    if (container == NULL)
        return (0);
    while (container)
    {
        i = 0;
        while (container->str_buf[i] && i < BUFFER_SIZE)
        {
            if (container->str_buf[i++] == '\n')
                return (1);
        }
        container = container->next_list;
    }
    return (0);
}

tmp_list CH_Lcontain(tmp_list *container)
{
    if (container == NULL)
        return (NULL);
    while (container->next_list)
        container = container->next_list;
    return (container);
}


void append(tmp_list **container, char *buffer)
{
    tmp_list *n_contain;
    tmp_list *l_contain;

    l_contain = CH_Lcontain(*container);
    n_contain = malloc(sizeof(tmp_list));
    if (n_contain == NULL)
        return ;
    n_contain->str_buf = buffer;
    n_contain->next_list = NULL;
    if (*container == NULL)
    {
        *container = n_contain;
        return ;
    }
}

void build_container(tmp_list **container, int fd)
{
    int read_status;
    char *buf;

    if (*container == NULL)
        return ;
    while (!ft_isnewline(*container))
    {
        buf = malloc(BUFFER_SIZE + 1);
        if (buf == NULL)
            return ;
        read_status = read(fd, buf, BUFFER_SIZE);
        if (read_status <= 0)
        {
            free (buf);
            return ;
        }
        buf[read_status] = '\0';
        append(container, buf);
    }
}

char *get_next_line(int fd)
{
    static tmp_list *container;
    char *new_line;

    container = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, new_line, 0) < 0)
        return NULL;
    build_container(&container, fd);
    if (container == NULL)
        return NULL;

}
