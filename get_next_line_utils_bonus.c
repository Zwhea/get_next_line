/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:27:27 by wangthea          #+#    #+#             */
/*   Updated: 2022/11/30 17:56:13 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	c2;

	if (!s || !c)
		return (NULL);
	i = 0;
	c2 = (char) c;
	while (s[i] && s[i] != c2)
		i++;
	if (s[i] == c2)
		return ((char *) &s[i]);
	return (NULL);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*array;
	size_t	i;

	i = 0;
	if (size > 0 && count > (SIZE_MAX / size))
		return (NULL);
	array = (char *)malloc(count * size);
	if (!array)
		return (NULL);
	while (i < count)
	{
		array[i] = '\0';
		i++;
	}
	return (array);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_join;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 && !s2)
		return (NULL);
	str_join = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str_join)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			str_join[i] = s1[i];
	if (s2)
		while (s2[j])
			str_join[i++] = s2[j++];
	free(s1);
	return (str_join);
}
