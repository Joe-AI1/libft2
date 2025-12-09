/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:47:28 by pukchayn          #+#    #+#             */
/*   Updated: 2025/12/04 00:25:28 by pukchayn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	findnumberfairfont(char **box, int num)
{
	int			i;
	int			x;
	long int	numbox;
	long int	numnear;

	i = 0;
	x = -1;
	numnear = (long int)checkmax(box) - (long int)num;
	if (num > checkmax(box))
		return (checkmax(box));
	while (box[i] != NULL)
	{
		numbox = (long int)num - (long int)ft_atoi(box[i]);
		if ((ft_atoi(box[i]) < num && numbox < numnear && box > 0)
			|| (ft_atoi(box[i]) < num && (numnear == checkmax(box) - num)))
		{
			x = i;
			numnear = numbox;
		}
		i++;
	}
	if (x == -1)
		return (checkmax(box));
	return (ft_atoi(box[x]));
}

int	pushbackcheck(char **box, int num)
{
	int			i;
	int			x;
	long int	numbox;
	long int	numnear;

	i = 0;
	x = -1;
	numnear = (long int)num - (long int)checkmin(box);
	if (num > checkmax(box))
		return (checkmin(box));
	while (box[i] != NULL)
	{
		numbox = (long int)ft_atoi(box[i]) - (long int)num;
		if ((ft_atoi(box[i]) > num && numbox < numnear)
			|| (ft_atoi(box[i]) > num && (numnear == numbox))
			|| (ft_atoi(box[i]) > num && (x == -1)))
		{
			x = i;
			numnear = numbox;
		}
		i++;
	}
	if (x == -1)
		return (checkmin(box));
	return (ft_atoi(box[x]));
}

void	pushback(char **box, char **box2, int ar)
{
	int	i;

	i = boxlen(box2);
	while (i != 0)
	{
		docommand(box, pushbackcheck(box, ft_atoi(box2[i - 1])), 0);
		pushboxlen(box, box2, 1, ar);
		i--;
	}
	rotatetillperfect(box);
}

void	fillbox(char **box2, int ar)
{
	int	p;

	p = 0;
	while (p != ar)
	{
		box2[p] = NULL;
		p++;
	}
}

void	pushcheck(int ar, char **box)
{
	char	**box2;
	int		i;
	int		x;

	i = 0;
	x = ar;
	box2 = malloc(sizeof(char *) * (ar));
	fillbox(box2, ar);
	while (x != 4 && i != 2)
	{
		pushboxlen(box, box2, 0, ar);
		x--;
		i++;
	}
	while (x != 4)
	{
		checktarget(box, box2);
		pushboxlen(box, box2, 0, ar);
		x--;
	}
	lastthree(box);
	pushback(box, box2, ar);
	freethedangbox(box2);
}
