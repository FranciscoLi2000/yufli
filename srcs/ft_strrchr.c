#include "libft.h"
char	*ft_strrchr(const char *s, int c)
{
	const char	*last;
	int	i;

	last = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			last = s[i];
		i++;
	}
	if (c == '\0')
		return ((char)s[i]);
	return ((char *)last);
}
