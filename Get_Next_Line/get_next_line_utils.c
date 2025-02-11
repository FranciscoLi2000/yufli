#include "get_next_line.h"
char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}
char	*ft_strdup(const char *s)
{
	char	*dup;
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
char	*ft_substr(char *s, int start, int len)
{
	char	*sub;
	int	i;

	i = 0;
	if (!s || start >= ft_strlen(s))
		return (NULL);
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
