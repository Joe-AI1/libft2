#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

size_t strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int isnewline(t_contain *stash)
{
	int	i;

	if (stash == NULL)
		return (0);
	while (stash)
	{
		i = 0;
		while (stash->str_buf[i] && i < BUFFER_SIZE)
		{
			if (stash->str_buf[i] == '\n')
				return (1);
			i++;
		}
		stash = stash->next;
	}
	return (0);
}

t_contain *lastnode(t_contain *stash)
{
	if (stash == NULL)
		return (NULL);
	while (stash->next)
		stash = stash->next;
	return (stash);
}

char *add_stash(char *stash, char *buffer)
{
	char	*joined_str;
	size_t	i;
	size_t	j;

	if (!stash)
	{
		stash = (char *)malloc(1 * sizeof(char));
		if (stash == NULL)
			return (NULL);
		stash[0] = '\0';
	}
	joined_str = malloc(sizeof(char) * (strlen(stash) + strlen(buffer) + 1));
	if (!joined_str)
		return (NULL);
	i = 0;
	while (stash[i] != '\0')
	{
		joined_str[i] = stash[i];
		i++;
	}
	j = 0;
	while (buffer[j])
		joined_str[i++] = buffer[j++];
	joined_str[i] = '\0';
	return (joined_str);
}

char	*get_line(t_contain *stash)
{
	char	*line;
	size_t	i;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash->str_buf[i] && stash->str_buf[i] != '\n')
		i++;
	if (stash->str_buf[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (line == NULL)
		return (NULL);
	j = 0;
	while (stash)
	{
		while (stash->str_buf[i])
		{
			line[j++] = stash->str_buf[i];
			if (stash->str_buf[i] == '\n')
			{
				line[j] = '\0';
				return (line);
			}
			i++;
		}
		stash = stash->next;
		i = 0;
	}
	line[j] = '\0';
	return (line);
}

void clear_malloc(t_contain **container, t_contain *c_contain)
{
	t_contain	*tmp;

	while (*container)
	{
		tmp = (*container)->next;
		free((*container)->str_buf);
		free(*container);
		*container = tmp;
	}
	*container = NULL;
	if (c_contain->str_buf[0])
		*container = c_contain;
	else
	{
		free(c_contain->str_buf);
		free(c_contain);
	}
}	

void	collect_stash(t_contain **stash, int fd)
{
	int		read_status;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return ;
	read_status = 1;
	while (!isnewline(*stash) && read_status != 0) // when read all data and no newline, read_status becomes 0, stop reading
	{
		read_status = read(fd, buffer, BUFFER_SIZE);
		if (read_status == -1)
		{
			free(buffer);
			free(*stash); // free the stash if read error occurs
			*stash = NULL; // set stash to NULL to indicate it's empty
			return ;
		}
		buffer[read_status] = '\0';
		*stash = ft_strjoin(*stash, buffer);
	}
	free(buffer);
}

char	*get_next_line(int fd)
{
	static t_contain	*stash;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	collect_stash(&stash, fd);
	if (stash == NULL)
		return (NULL);
	line = get_line(stash);
	clear_malloc(&stash, NULL);
	return (line);
}
