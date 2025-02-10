#include "libft.h"
#include <stdlib.h>
/* 辅助函数1：跳过分隔符 */
static const char	*skip_delimiters(const char *s, char c)
{
	while (*s == c && *s)
		s++;
	return (s);
}
/* 辅助函数2：统计单词数 */
static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		s = skip_delimiters(s, c);
		if (*s)
			count++;
		s = ft_strchr(s, c);
	}
	return (count);
}
/* 辅助函数3：提取单词 */
static char	*extract_word(const char *s, char c)
{
	const char	*end;

	end = ft_strchr(s, c);
	if (!end)
		end = s + ft_strlen(s);
	return (ft_substr(s, 0, end - s));
}
/* 主函数 */
char	**ft_split(const char *s, char c)
{
	size_t	num_words;
	size_t	i;
	char	**result;

	if (!s)
		return (NULL);
	num_words = count_words(s, c);
	result = ft_calloc(num_words + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		s = skip_delimiters(s, c);
		if (!*s)
			break ;
		result[i] = extract_word(s, c);
		if (!result[i])
		{
			while (i > 0)
				free(result[--i]);
			free(result);
			return (NULL);
		}
		s += ft_strlen(result[i]);
		i++;
	}
	return (result);
}
