/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:56:59 by evella            #+#    #+#             */
/*   Updated: 2023/10/23 15:39:04 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_line
{
	char	*str;
	char	buffer[BUFFER_SIZE + 1];
	int		oread;
}			t_line;

char	*get_next_line(int fd);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memset(void *str, int c, size_t count);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char const *s2);

#endif
