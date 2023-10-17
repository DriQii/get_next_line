/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:00:52 by evella            #+#    #+#             */
/*   Updated: 2023/10/17 18:57:53 by evella           ###   ########.fr       */
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

void *ft_realloc(void *ptr, size_t size)
{
	void *newptr;

	newptr = NULL;
	if(ptr)
	{
		newptr = ft_calloc(1, size);
		if(!newptr)
			return (NULL);
		ft_memcpy(newptr, ptr, size - BUFFER_SIZE);
		free(ptr);
	}
	else
		newptr = ft_calloc(1, size);
	return(newptr);

}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
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
	ft_memset(temp, '\0',count * size);
	return ((void *)temp);
}