/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushcommand3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 22:22:39 by pukchayn          #+#    #+#             */
/*   Updated: 2025/12/04 00:25:28 by pukchayn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	docommandforboth(char **box, char **box2, int boxnum1, int boxnum2)
{
	int	count1;
	int	count2;
	int	count;

	count1 = locationchecker(box, boxnum1);
	count2 = locationchecker(box2, boxnum2);
	count = commandlencheck(box, boxnum1) + commandlencheck(box2, boxnum2);
	while (count != 0)
	{
		if (count1 >= (boxlen(box) / 2) && count2 >= (boxlen(box2) / 2)
			&& count != 1 && locationchecker(box2, boxnum2) != boxlen(box2) - 1
			&& locationchecker(box, boxnum1) != boxlen(box) - 1)
		{
			shift_upforboth(box, box2);
			count--;
		}
		else if (count1 < (boxlen(box) / 2) && count2 < (boxlen(box2) / 2)
			&& count != 1 && locationchecker(box2, boxnum2) != boxlen(box2) - 1
			&& locationchecker(box, boxnum1) != boxlen(box) - 1)
		{
			shift_downforboth(box, box2);
			count--;
		}
		count--;
	}
}

int	checktarget(char **box, char **box2)
{
	int	bestoption;
	int	bestoption2;
	int	holder;
	int	i;

	i = boxlen(box);
	holder = ft_atoi(box[i - 1]);
	bestoption2 = locationamount(box, box2, ft_atoi(box[i - 1]),
			findnumberfairfont(box2, ft_atoi(box[i - 1])));
	while (i != 0)
	{
		bestoption = locationamount(box, box2, ft_atoi(box[i - 1]),
				findnumberfairfont(box2, ft_atoi(box[i - 1])));
		if (bestoption < bestoption2)
		{
			bestoption2 = bestoption;
			holder = ft_atoi(box[i - 1]);
		}
		i--;
	}
	docommandforboth(box, box2, holder, findnumberfairfont(box2, holder));
	docommand(box, holder, 0);
	docommand(box2, findnumberfairfont(box2, holder), 1);
	return (holder);
}

void	rotatetillperfect(char **box)
{
	int	x;
	int	b;

	x = locationchecker(box, checkmin(box));
	b = boxlen(box) / 2;
	if (x >= b)
	{
		while (checkmin(box) != ft_atoi(box[boxlen(box) - 1]))
			shift_up(box, 0);
	}
	else
	{
		while (checkmin(box) != ft_atoi(box[boxlen(box) - 1]))
			shift_down(box, 0);
	}
}

int	countboxlen(int ar, char **ag)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i != ar)
	{
		count += howmuchchar(ag[i], ' ');
		i++;
	}
	return (count);
}
