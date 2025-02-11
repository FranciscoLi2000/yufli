#include <stdlib.h>
#include <stddef.h>
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	/* 计算两个字符串的长度 */
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	/* 分配足够大的内存来存放 s1 + s2 + '\0' */
	joined = malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	/* 将 s1 复制到新字符串中 */
	ft_memcpy(joined, s1, len1);
	/* 将 s2 紧接在 s1 后面复制过去 */
	ft_memcpy(joined + len1, s2, len2);
	joined[len1 + len2] = '\0';
	return (joined);
}
