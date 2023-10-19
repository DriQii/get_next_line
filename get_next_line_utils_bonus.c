/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:00:52 by evella            #+#    #+#             */
/*   Updated: 2023/10/19 14:03:11 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

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
	ft_memset(temp, '\0',count * size);
	return ((void *)temp);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if(!src)
		return(NULL);
	dest = (char *)ft_calloc(sizeof(char) , (ft_strlen((char *)src) + 1));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		len;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
	{
		return (NULL);
	}
	ft_strcpy(str, (char *)s1);
	ft_strcpy(str + ft_strlen((char *) s1), (char *)s2);
	free(s1);
	return (str);
}