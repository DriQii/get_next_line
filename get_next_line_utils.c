/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:00:52 by evella            #+#    #+#             */
/*   Updated: 2023/10/23 15:39:07 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*dest_temp;
	const char	*src_temp;

	dest_temp = dest;
	src_temp = src;
	if (!dest_temp && !src_temp)
		return (NULL);
	while (len-- > 0)
		*dest_temp++ = *src_temp++;
	return (dest);
}

void	*ft_memset(void *str, int c, size_t count)
{
	char	*temp;

	temp = str;
	while (count-- > 0)
	{
		*temp++ = c;
	}
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	ft_memset(temp, '\0', count * size);
	return ((void *)temp);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s1)
		while (s1[i])
			i++;
	while (s2[j])
		j++;
	len = i + j + 1;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	if (s1)
		ft_memcpy(str, s1, i);
	ft_memcpy(str + i, s2, j + 1);
	if (s1)
		free(s1);
	return (str);
}
