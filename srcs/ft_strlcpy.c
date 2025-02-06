#include "libft.h"
#include <stddef.h>
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = 0;
	i = 0;
	while (src[srcsize] != '\0')
		srcsize++;
	if (dstsize > 0)
	{
		while ((i < dstsize - 1) && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}
