#include "libft.h"
#include <stddef.h>
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlelen;
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (i + needlelen <= len && haystack[i] != '\0')
	{
		if (ft_strncmp(&haystack[i], needle, needlelen) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
