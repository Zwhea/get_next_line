/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:27:25 by wangthea          #+#    #+#             */
/*   Updated: 2022/11/30 17:56:03 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{	
		free(stash);
		return (NULL);
	}
	new_stash = ft_calloc((ft_strlen(stash) - i) + 1, sizeof(char));
	if (!new_stash)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	free(stash);
	return (new_stash);
}

static char	*get_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	static char	*stash[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];

	line = NULL;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	i = 1;
	while (i > 0 && ft_strchr(stash[fd], '\n') == 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(stash[fd]);
			stash[fd] = NULL;
			return (NULL);
		}
		buffer[i] = '\0';
		stash[fd] = ft_strjoin(stash[fd], buffer);
	}
	line = get_line(stash[fd]);
	stash[fd] = get_stash(stash[fd]);
	return (line);
}
