/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:10:36 by joe               #+#    #+#             */
/*   Updated: 2026/02/19 12:12:56 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

int	isnewline(t_contain *container)
{
	int	i;

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
		container = container->next;
	}
	return (0);
}

int	fill_line(t_contain *container, char *str)
{
	int	i;
	int	len;

	len = 0;
	while (container)
	{
		i = 0;
		while (container->str_buf[i])
		{
			if (str)
				str[len++] = container->str_buf[i];
			if (container->str_buf[i++] == '\n')
			{
				if (str)
					str[len] = '\0';
				return (len);
			}
		}
		container = container->next;
	}
	if (str)
		str[len] = '\0';
	return (len);
}

void	clear_malloc(t_contain **container, t_contain *c_contain)
{
	t_contain	*tmp;

	if (*container == NULL)
		return ;
	while (*container)
	{
		tmp = (*container)->next;
		free((*container)->str_buf);
		free(*container);
		*container = tmp;
	}
	if (c_contain->str_buf[0] && c_contain)
		*container = c_contain;
	else
	{
		free(c_contain->str_buf);
		free(c_contain);
		*container = NULL;
	}
}
