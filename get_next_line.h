/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:26:47 by wangthea          #+#    #+#             */
/*   Updated: 2022/11/30 18:07:02 by wangthea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

//--------------------------------------------------------------base functions--

char	*get_next_line(int fd);

//-------------------------------------------------------------utils functions--

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);

#endif 