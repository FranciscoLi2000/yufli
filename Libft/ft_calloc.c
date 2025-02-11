#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
void	*ft_calloc(size_t num, size_t size)
{
	size_t	totsize;
	void	*ptr;

	totsize = num * size;
	ptr = malloc(totsize);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, totsize);
	return (ptr);
}
