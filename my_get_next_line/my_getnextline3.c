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

char  *ft_strchr(char *str, char c)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}

char *ft_strjoin(char *stash, char *buffer)
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
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

void clear_malloc(char *stash)
{
	size_t i;
	size_t j;
	char *new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (strlen(stash) - i + 1));
	if (new_stash == NULL)
		return (free(stash), NULL);
	j = 0;
	i += 1;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
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
	static t_contain	*container;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	collect_stash(&container, fd);
	if (container == NULL)
		return (NULL);
	line = get_line(container);
	clear_malloc(&container, NULL);
	return (line);
}
