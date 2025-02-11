#include "libft.h"
#include <stddef.h>
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	copylen;
	size_t	i;

	dstlen = 0;
	srclen = 0;
	while (dstlen < dstsize && dst[dstlen] != '\0')
		dstlen++;
	while (src[srclen] != '\0')
		srclen++;
	if (dstsize <= dstlen)
		return (dstlen + srclen);
	copylen = dstsize - dstlen - 1;
	i = 0;
	while (i < copylen && src[i] != '\0')
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
