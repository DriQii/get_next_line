#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_index
{
    int i;
    int j;
    int k;
} t_index;

char *get_next_line(int fd);
size_t	ft_strlen(const char *str);
void *ft_realloc(void *ptr, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memset(void *str, int c, size_t count);
void	*ft_calloc(size_t count, size_t size);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
