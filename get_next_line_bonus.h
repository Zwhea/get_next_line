/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:26:47 by wangthea          #+#    #+#             */
/*   Updated: 2022/12/01 08:41:38 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

//--------------------------------------------------------bonus base functions--

char	*get_next_line(int fd);

//-------------------------------------------------------bonus utils functions--

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);

#endif 