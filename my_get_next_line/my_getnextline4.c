#include "get_next_line4.h"
#include <stdlib.h>
#include <unistd.h>

size_t stash_len(t_contain *stash)
{
	size_t len;
	size_t i;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->str_buf[i] && stash->str_buf[i] != '\n')
		{
			len++;
			i++;
		}
		if (stash->str_buf[i] == '\n')
		{
			len++;
			break ;
		}
		stash = stash->next;
	}
	return (len);
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

t_contain *new_node(char *buffer, int read_status)
{
	t_contain *node;
	int i;

	i = 0;
	node = malloc(sizeof(t_contain));
	if (node == NULL)
		return (NULL);
	node->str_buf = malloc(read_status + 1);
	if (node->str_buf == NULL)
	{
		free(node);
		return (NULL);
	}
	while (i < read_status)
	{
		node->str_buf[i] = buffer[i];
		i++;
	}
	node->str_buf[read_status] = '\0';
	node->next = NULL;
	return (node);
}

void free_stash(t_contain **stash)
{
	t_contain	*tmp;

	while (*stash)
	{
		tmp = (*stash)->next; // move to the next node before freeing the current node
		free((*stash)->str_buf);
		free(*stash);
		*stash = tmp;
	}
}

t_contain *clear_stash(t_contain *stash, char *line)
{
	t_contain *node;
	char *left_over;
	size_t i;

	if (line == NULL)
	{
		free_stash(&stash);
		return (NULL);
	}
	i = 0;
	while (stash->str_buf[i] && stash->str_buf[i] != '\n')
		i++;
	if (!stash -> str_buf[i]) // if no newline, free the whole stash and return NULL
	{
		free_stash(&stash);
		return (NULL);
	}
	left_over = stash -> str_buf + i + 1; // left_over is the part after the newline, we will keep it in the stash for the next call of get_next_line
	i = 0;
	while (left_over[i])
		i++;
	node = new_node(left_over, i);
	free_stash(&stash);
	return (node);
}


static int copy_node(t_contain *node, char *line, size_t i)
{
	size_t j;

	j = 0;
	while (node->str_buf[j] && node ->str_buf[j] != '\n')
		line[i++] = node -> str_buf[j++];
	if (node->str_buf[j] == '\n')
		line[i++] = '\n';
	return (i);
}

char *extract_line(t_contain *stash)
{
	char *line;
	size_t i;
	size_t len;
	t_contain *tmp;

	len = stash_len(stash);
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	tmp = stash;
	while (tmp)
	{
		i = copy_node(tmp, line, i);
		if (tmp->str_buf[i - 1] == '\n') // if we just copy a newline, we can stop copying because we only want to return one line
			break ;
		tmp = tmp->next;
	}
	line[i] = '\0';
	return (line);
}

t_contain *append_node(t_contain *stash, t_contain *node)
{

	t_contain *tmp;

	if (stash == NULL)
		return (node);
	tmp = stash; // pointer in same address but can move to next node, so we can keep the head of the list 
	//and can expand the list without losing the head of the list
	while (tmp->next)
		tmp = tmp->next; // move to the last node of the list
	tmp->next = node;
	return (stash);
}

t_contain	*collect_stash(t_contain *stash, int fd)
{
	int		read_status;
	char	*buffer;
	t_contain	*node;

	buffer = malloc((BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	read_status = 1;
	while (!isnewline(stash) && read_status != 0) // when read all data and no newline, read_status becomes 0, stop reading
	{
		read_status = read(fd, buffer, BUFFER_SIZE);
		if (read_status <= 0) // <= 0 mean EOF(still have data left) but if < 0 means error, both case we should stop reading
			break;
		buffer[read_status] = '\0';
		node = new_node(buffer, read_status);
		if (node == NULL)
		{
			free_stash(&stash);
			stash = NULL;
			break;
		}
		stash = append_node(stash, node);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static t_contain	*stash;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stash = collect_stash(stash, fd);
	if (stash == NULL)
		return (NULL);
	line = extract_line(stash);
	stash = clear_stash(stash, line);
	return (line);
}
