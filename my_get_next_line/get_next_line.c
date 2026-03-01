/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:10:15 by joe               #+#    #+#             */
/*   Updated: 2026/03/01 00:37:55 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

void	append(t_contain **container, char *str)
{
	t_contain	*n_contain;
	t_contain	*current;

	n_contain = malloc(sizeof(t_contain));
	if (n_contain == NULL)
		return ;
	n_contain->str_buf = str;
	n_contain->next = NULL;
	if (*container == NULL)
	{
		*container = n_contain;
		return ;
	}
	current = *container;
	while (current->next)
		current = current->next;
	current->next = n_contain;
}

void	clear_container(t_contain **container)
{
	t_contain	*l_contain;
	t_contain	*c_contain;
	char		*buf;
	int			i;
	int			j;

	l_contain = *container;
	while (l_contain && l_contain->next)
		l_contain = l_contain->next;
	if (!l_contain)
		return ;
	buf = malloc(BUFFER_SIZE + 1);
	c_contain = malloc(sizeof(t_contain));
	if (buf == NULL || c_contain == NULL)
		return ;
	i = 0;
	while (l_contain->str_buf[i] && l_contain->str_buf[i] != '\n')
		i++;
	j = 0;
	while (l_contain->str_buf[i] && l_contain->str_buf[++i])
		buf[j++] = l_contain->str_buf[i];
	buf[j] = '\0';
	c_contain->str_buf = buf;
	c_contain->next = NULL;
	clear_malloc(container, c_contain);
}

char	*get_line(t_contain *container)
{
	char	*line;
	int		len;

	if (container == NULL)
		return (0);
	len = fill_line(container, NULL);
	line = malloc(len + 1);
	if (line == NULL)
		return (0);
	fill_line(container, line);
	return (line);
}

void	build_container(t_contain **container, int fd)
{
	int		read_status;
	char	*buffer;

	while (!isnewline(*container))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		read_status = read(fd, buffer, BUFFER_SIZE);
		if (read_status <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[read_status] = '\0';
		append(container, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_contain	*container;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	build_container(&container, fd);
	if (container == NULL)
		return (NULL);
	line = get_line(container);
	clear_container(&container);
	return (line);
}
