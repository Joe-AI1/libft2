/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkercommnad.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 22:14:32 by pukchayn          #+#    #+#             */
/*   Updated: 2025/10/13 22:15:47 by pukchayn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	checkmin(char **box)
{
	int	smallest;
	int	i;

	i = 0;
	smallest = ft_atoi(box[0]);
	while (box[i] != NULL)
	{
		if (smallest > ft_atoi(box[i]))
			smallest = ft_atoi(box[i]);
		i++;
	}
	return (smallest);
}

int	checkmax(char **box)
{
	int	biggest;
	int	i;

	i = 0;
	biggest = ft_atoi(box[0]);
	while (box[i] != NULL)
	{
		if (biggest < ft_atoi(box[i]))
			biggest = ft_atoi(box[i]);
		i++;
	}
	return (biggest);
}

int	locationchecker(char **box, int num)
{
	int	loc;

	loc = 0;
	while (box[loc] != NULL)
	{
		if (ft_atoi(box[loc]) == num)
			break ;
		loc++;
	}
	return (loc);
}

int	boxlen(char **box)
{
	int	i;

	i = 0;
	while (box[i] != NULL)
		i++;
	return (i);
}

int	locationamount(char **box, char **box2, int boxnum1, int boxnum2)
{
	int	count1;
	int	count2;
	int	box1len;
	int	box2len;
	int	count;

	count = 0;
	box1len = boxlen(box) / 2;
	box2len = boxlen(box2) / 2;
	count1 = locationchecker(box, boxnum1) + 1;
	count2 = locationchecker(box2, boxnum2) + 1;
	if (locationchecker(box, boxnum1) == boxlen(box) - 1)
		count = 0;
	else if (count1 < box1len)
		count = count1;
	else if (count1 >= box1len)
		count = boxlen(box) - count1;
	if (locationchecker(box2, boxnum2) == 0)
		count += 1;
	else if (count2 < box2len)
		count += count2;
	else if (count2 >= box2len)
		count += boxlen(box2) - count2;
	return (count);
}
