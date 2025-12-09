/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushcommand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:03:48 by pukchayn          #+#    #+#             */
/*   Updated: 2025/12/03 17:26:01 by pukchayn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	pushboxlen(char **box, char **box2, int t, int ar)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (box[i] != NULL)
		i++;
	while (box2[x] != NULL)
		x++;
	if (t == 0 && x != ar && i != ar)
	{
		box2[x] = putstr(box[i - 1]);
		free(box[i - 1]);
		box[i - 1] = NULL;
		box2[x + 1] = NULL;
		write(1, "pb\n", 3);
	}
	else if (t == 1 && x != ar && i != ar)
	{
		box[i] = putstr(box2[x - 1]);
		free(box2[x - 1]);
		box2[x - 1] = NULL;
		box[i + 1] = NULL;
		write(1, "pa\n", 3);
	}
}

void	swapbox(char **box, int x)
{
	char	*tmp;
	int		i;

	i = 0;
	while (box[i] != NULL)
		i++;
	tmp = putstr(box[i - 1]);
	free(box[i - 1]);
	box[i - 1] = putstr(box[i - 2]);
	free(box[i - 2]);
	box[i - 2] = putstr(tmp);
	free(tmp);
	if (x == 0)
		write(1, "sa\n", 3);
	else if (x == 1)
		write(1, "sb\n", 3);
}

void	swapboth(char **box, char **box2)
{
	swapbox(box, 2);
	swapbox(box2, 3);
	write(1, "ss\n", 3);
}

void	shift_up(char **box, int t)
{
	char	*tmp;
	int		i;

	i = 0;
	while (box[i] != NULL)
		i++;
	i = i - 1;
	while (i != 0)
	{
		tmp = putstr(box[i]);
		free(box[i]);
		box[i] = putstr(box[i - 1]);
		free(box[i - 1]);
		box[i - 1] = putstr(tmp);
		free(tmp);
		i--;
	}
	if (t == 0)
		write(1, "ra\n", 3);
	else if (t == 1)
		write(1, "rb\n", 3);
}

void	shift_down(char **box, int t)
{
	char	*tmp;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (box[x] != NULL)
		x++;
	while (i != x - 1)
	{
		tmp = putstr(box[i]);
		free(box[i]);
		box[i] = putstr(box[i + 1]);
		free(box[i + 1]);
		box[i + 1] = putstr(tmp);
		free(tmp);
		i++;
	}
	if (t == 0)
		write(1, "rra\n", 4);
	else if (t == 1)
		write(1, "rrb\n", 4);
}
