/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmin-kha <waiyanminkhant027@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:27:54 by wmin-kha          #+#    #+#             */
/*   Updated: 2025/09/10 20:31:50 by wmin-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_and_fill(int fd, char *leftover, char *buffer);
char	*set_line(char *line);

char	*get_next_line(int fd)
{
	static char	*leftover[MAX_READ_OPEN];
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(leftover[fd]);
		free(buffer);
		buffer = NULL;
		leftover[fd] = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = read_and_fill(fd, leftover[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	leftover[fd] = set_line(line);
	return (line);
}

char	*read_and_fill(int fd, char *leftover, char *buffer)
{
	ssize_t	read_res;
	char	*tmp;

	read_res = 1;
	while (read_res > 0)
	{
		read_res = read(fd, buffer, BUFFER_SIZE);
		if (read_res < 0)
		{
			free(leftover);
			return (NULL);
		}
		else if (read_res == 0)
			break ;
		buffer[read_res] = 0;
		if (!leftover)
			leftover = ft_strdup("");
		tmp = leftover;
		leftover = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (leftover);
}

char	*set_line(char *line)
{
	size_t	i;
	char	*tmp_leftover;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[i + 1] == 0)
		return (NULL);
	tmp_leftover = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (tmp_leftover == NULL)
	{
		free(tmp_leftover);
		tmp_leftover = NULL;
	}
	line[i + 1] = 0;
	return (tmp_leftover);
}
