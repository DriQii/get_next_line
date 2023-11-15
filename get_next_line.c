/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:01:17 by evella            #+#    #+#             */
/*   Updated: 2023/10/23 15:47:50 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_end_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
		return (-1);
	return (i);
}

void	ft_write_rest(char rest[1024][BUFFER_SIZE + 1], char *buffer, int fd)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	i = 0;
	temp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!temp)
		return ;
	ft_memcpy(temp, buffer, BUFFER_SIZE);
	ft_memset(rest[fd], 0, BUFFER_SIZE + 1);
	while (temp[i] != '\n' && temp[i])
		i++;
	if (temp[i] == '\n')
		i++;
	while (temp[i])
	{
		rest[fd][j++] = temp[i];
		i++;
	}
	free(temp);
}

char	*ft_cut_line(char *str)
{
	int		i;
	char	*newstr;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	newstr = ft_calloc(sizeof(char), i + 1);
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, str, i);
	free(str);
	return (newstr);
}

char	*get_next_line(int fd)
{
	static char	rest[1024][BUFFER_SIZE + 1];
	t_line		line;

	line.oread = 1;
	line.str = NULL;
	ft_memset(line.buffer, 0, BUFFER_SIZE + 1);
	if (rest[fd][0])
	{
		line.str = ft_strjoin(line.str, rest[fd]);
		ft_write_rest(rest, rest[fd], fd);
		if (ft_check_end_line(line.str) != -1)
			return (ft_cut_line(line.str));
	}
	while (ft_check_end_line(line.buffer) == -1)
	{
		ft_memset(line.buffer, 0, BUFFER_SIZE + 1);
		line.oread = read(fd, line.buffer, BUFFER_SIZE);
		if (line.oread == 0 && line.str)
			return (ft_cut_line(line.str));
		else if (line.oread <= 0)
			return (NULL);
		line.str = ft_strjoin(line.str, line.buffer);
	}
	ft_write_rest(rest, line.buffer, fd);
	return (ft_cut_line(line.str));
}
