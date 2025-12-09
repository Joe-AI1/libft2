/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startinginputcheck.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:20:28 by pukchayn          #+#    #+#             */
/*   Updated: 2025/12/04 01:34:00 by pukchayn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	checknum(char **ag, char *str, int ar, char **box)
{
	int		i;
	int		x;
	int		count;

	x = 0;
	if (!str)
		return (1);
	while (++x != countboxlen(ar, ag) - 1)
	{
		i = 0;
		count = 0;
		while (box[x][i] != '\0' && str[i] != '\0')
		{
			if (box[x][i] == str[i] && x != locationchecker(box, ft_atoi(str)))
				count++;
			if (count == ft_strlen2(str)
				&& ft_strlen2(str) == ft_strlen2(box[x]))
				return (1);
			i++;
		}
	}
	return (0);
}

int	checkchar(char *str)
{
	int	i;
	int	negcount;

	negcount = 0;
	i = 0;
	if (!str)
		return (1);
	while (str[i] != '\0' && str[i] != ',')
	{
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] == '-')
				|| (str[i] == '+')) || negcount > 1)
			return (1);
		if ((str[i] == '-' && i != 0) || (str[i] == '+' && i != 0))
			return (1);
		else if ((str[i] == '-') || (str[i] == '+'))
			negcount++;
		i++;
	}
	if ((negcount == ft_strlen2(str))
		|| ((str[0] == '-' && str[1] == '0') && i == 2))
		return (1);
	return (0);
}

int	checknumlen(char *str)
{
	long int	max;
	long int	min;
	long int	num;

	if (!str)
		return (1);
	max = 2147483647;
	min = -2147483648;
	num = ft_atoilong(str);
	if (num > max || num < min)
		return (1);
	return (0);
}

int	nullcheck(char **box, int ar)
{
	int		i;
	char	**box2;

	i = ar - 1;
	while (i != 0)
	{
		box2 = ft_split(box[i], ' ');
		if (box2[0] == NULL)
		{
			freethedangbox(box2);
			return (1);
		}
		i--;
		freethedangbox(box2);
	}
	return (0);
}

int	realchecker(char *str, char **ag, int ar)
{
	char	**box;

	if (nullcheck(ag, ar) == 1)
		return (1);
	box = givebox(ar, ag);
	if (checkchar(str) == 0 && checknum(ag, str, ar, box) == 0
		&& checknumlen(str) == 0)
	{
		freethedangbox(box);
		return (0);
	}
	else
	{
		freethedangbox(box);
		write(2, "Error\n", 6);
		return (1);
	}
}
