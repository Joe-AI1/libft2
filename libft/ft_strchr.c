/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krijooyc <krijooyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:43:39 by krijooyc          #+#    #+#             */
/*   Updated: 2025/10/03 16:43:51 by krijooyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	const char	*a;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			a = &s[i];
			return ((char *)a);
		}
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}
