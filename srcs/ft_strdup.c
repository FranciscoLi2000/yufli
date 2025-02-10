#include "libft.h"
#include <stdlib.h>
#include <stddef.h>
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new;
	char	*start;

	len = ft_strlen(s) + 1;
	new = malloc(len * sizeof(char));
	if (!new || !s)
		return (NULL);
	start = new;
	while (*s != '\0')
	{
		*new = *s;
		s++;
		new++;
	}
	*new = '\0';
	return (start);
}
