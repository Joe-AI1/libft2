/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krijooyc <krijooyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:26:23 by krijooyc          #+#    #+#             */
/*   Updated: 2025/10/03 18:15:47 by krijooyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tmp;
	size_t	s_len;

	if (!s)
		return (NULL);
	i = 0;
	s_len = len;
	i = ft_strlen(s);
	if (start >= i)
		return (ft_strdup(""));
	if (start + len > i)
		s_len = i - start;
	tmp = ft_calloc(s_len + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (s_len--)
		tmp[i++] = s[start++];
	tmp[i] = '\0';
	return (tmp);
}
