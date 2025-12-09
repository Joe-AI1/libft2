/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:26:35 by pukchayn          #+#    #+#             */
/*   Updated: 2025/12/04 01:34:20 by pukchayn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

// void test(char **box)
// {
// 	int i;
// 	i = 0;
// 	while (box[i] != NULL)
// 	{
// 		printf("%d) numstr: %s\n",i + 1,box[i]);
// 		i++;
// 	}
// 	printf("NUll: %s\n",box[i]);
// 	printf("----------------------------\n");
// }

char	**givebox(int ar, char **ag)
{
	int		i;
	int		x;
	int		num;
	char	**box;
	char	**box2;

	x = 0;
	box = malloc(sizeof(char *) * (countboxlen(ar, ag)));
	i = ar - 1;
	while (i != 0)
	{
		num = howmuchchar(ag[i], ' ');
		box2 = ft_split(ag[i], ' ');
		while (num != 0)
		{
			box[x] = putstr(box2[num - 1]);
			x++;
			num--;
		}
		freethedangbox(box2);
		i--;
	}
	box[countboxlen(ar, ag) - 1] = NULL;
	return (box);
}

char	*putstr(char *str)
{
	int		i;
	char	*box;

	if (!str)
		return (NULL);
	i = 0;
	box = malloc(sizeof(char) * ft_strlen2(str) + 1);
	while (str[i] != '\0')
	{
		box[i] = str[i];
		i++;
	}
	box[i] = '\0';
	return (box);
}

void	pushstart(int ar, int x, char **box, char **ag)
{
	if (checkifalreadydone(box) == 0)
		return ;
	if (boxlen(box) > 2)
		pushcheck(boxlen(box) + 1, box);
	else
		smallswap(box, boxlen(box));
}

int	main(int ar, char **ag)
{
	int		i;
	int		num;
	char	**box;
	char	**box2;

	i = ar;
	while (--i)
	{
		num = howmuchchar(ag[i], ' ');
		box2 = ft_split(ag[i], ' ');
		while (num != 0)
		{
			if (realchecker(box2[num - 1], ag, ar) == 1)
			{
				freethedangbox(box2);
				return (1);
			}
			num--;
		}
		freethedangbox(box2);
	}
	box = givebox(ar, ag);
	pushstart(ar, countboxlen(ar, ag), box, ag);
	freethedangbox(box);
	return (0);
}
