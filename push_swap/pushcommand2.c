/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushcommand2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 22:17:05 by pukchayn          #+#    #+#             */
/*   Updated: 2025/12/04 00:33:12 by pukchayn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	shift_upforboth(char **box, char **box2)
{
	shift_up(box, 3);
	shift_up(box2, 3);
	write(1, "rr\n", 3);
}

void	shift_downforboth(char **box, char **box2)
{
	shift_down(box, 3);
	shift_down(box2, 3);
	write(1, "rrr\n", 4);
}

void	docommand(char **box, int boxnum1, int t)
{
	int	count1;
	int	box1len;
	int	count;

	count = 0;
	box1len = (boxlen(box) / 2);
	count1 = locationchecker(box, boxnum1) + 1;
	if (count1 >= box1len && count1 != 1)
	{
		count = boxlen(box) - count1;
		while (count != 0)
		{
			shift_up(box, t);
			count--;
		}
	}
	else if (count1 < box1len || count1 == 1)
	{
		count = count1;
		while (count != 0)
		{
			shift_down(box, t);
			count--;
		}
	}
}

int	commandlencheck(char **box, int boxnum1)
{
	int	count1;
	int	box1len;
	int	count;

	count = 0;
	box1len = (boxlen(box) / 2);
	count1 = locationchecker(box, boxnum1) + 1;
	if (count1 >= box1len)
		count = boxlen(box) - count1;
	else if (count1 < box1len)
		count = count1;
	return (count);
}
