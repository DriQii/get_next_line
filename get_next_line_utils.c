/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:00:52 by evella            #+#    #+#             */
/*   Updated: 2023/10/13 19:16:00 by evella           ###   ########.fr       */
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
		newptr = malloc(size);
		if(!newptr)
			return (NULL);
		ft_memcpy(newptr, ptr, size - BUFFER_SIZE);
		free(ptr);
	}
	else
		newptr = malloc(size);
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
