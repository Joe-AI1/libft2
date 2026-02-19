/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:20:21 by joe               #+#    #+#             */
/*   Updated: 2026/02/19 08:17:11 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

int ft_isnewline(tmp_list *str)
{
    int i;

    if (str == NULL)
        return (0);
    while (str)
    {
        i = 0;
        while (str->str_buf[i] && i < BUFFER_SIZE)
        {
            if (str->str_buf[i] == '\n')
                return (1);
            i++;
        }
        str = str->next;
    }
    return (0);
}

tmp_list *find_last_node(tmp_list *str)
{
    if (str == NULL)
        return (NULL);
    while (str->next)
        str = str->next;
    return (str);
}

int len_to_newline(tmp_list *str)
{
    int len;
    int i;

    len = 0;
    while (str)
    {
        i = 0;
        while (str->str_buf[i])
        {
            if (str->str_buf[i] == '\n')
                return (len + i);
            i++;
        }
        len += i;
        str = str->next;
    }
    return (len);
}

void copy_str(tmp_list *list, char *str)
{
    int i;
    int j;

    j = 0;
    while (list)
    {
        i = 0;
        while (list->str_buf[i])
        {
            str[j] = list->str_buf[i];
            if (list->str_buf[i] == '\n')
            {
                str[j] = '\n';
                str[j + 1] = '\0';
                return ;
            }
            i++;
            j++;
        }
        list = list->next;
    }
    str[j] = '\0';
}

void dealloc(tmp_list **str, tmp_list *clean_node, char *buffer)
{
    tmp_list *tmp;
    
    if (*str == NULL)
        return ;
    while (*str)
    {
        tmp = (*str)->next;
        free((*str)->str_buf);
        free(*str);
        *str = tmp;
    }
    *str = NULL;
    if (clean_node->str_buf[0])
        *str = clean_node;
    else
    {
        free(buffer);
        free(clean_node);
    }
}

char *get_line(tmp_list *str)
{
    int len;
    char *next_str;

    len = 0;
    if (str == NULL)
        return (NULL);
    len = len_to_newline(str);
    next_str = malloc(len + 1);
    if (next_str == NULL)
        return (NULL);
    copy_str(str, next_str);
    return (next_str);
}

void append(tmp_list **str, char *buffer)
{
    tmp_list *new_node;
    tmp_list *last_node;

    last_node = find_last_node(*str);
    new_node = malloc(sizeof(tmp_list));
    if (new_node == NULL)
        return ;
    new_node->str_buf = buffer;
    new_node->next = NULL;
    if (*str == NULL)
    {
        *str = new_node;
        return ;
    }
    last_node = *str;
    while (last_node->next)
        last_node = last_node->next;
    last_node->next = new_node;
}

void create_list(tmp_list **str, int fd)
{
    int char_read;
    char *buffer;

    while (!ft_isnewline(*str))
    {
        buffer = malloc (BUFFER_SIZE + 1);
        if (buffer == NULL)
            return ;
        char_read = read(fd, buffer, BUFFER_SIZE);
        if (!char_read)
        {
            free(buffer);
            return ;
        }
        buffer[char_read] = '\0';
        append(str, buffer);
    }
}

char *get_next_line(int fd)
{
    static tmp_list *list = NULL;
    char *new_line;
    //filedescripter are only positive
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, new_line, 0) < 0)
        return NULL;
    //Creat my list till stumvle into \n
    create_list(&list, fd);
    if (list==NULL)
        return NULL;
    
        //fetch the line from list
    new_line = get_line(list);

    polish_list(&list);
    return new_line;
}