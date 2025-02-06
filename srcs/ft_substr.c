#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	substrlen;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	/* 如果 start 超出字符串 s 的长度，则返回一个仅包含终止符的空字符串 */
	if (start >= s_len)
	{
		substr = malloc(1);
		if (substr)
			substr[0] = '\0';
		return (substr);
	}
	/* 计算实际可复制的长度，不能超过 s[start] 后剩余的字符数 */
	if (len > s_len - start)
		substrlen = slen - start;
	else
		substrlen = len;
	/* 为子字符串分配内存，多分配 1 个字节用于存储终止符 */
	substr = malloc(substrlen + 1);
	if (substr == NULL)
		return (NULL);
	/* 复制子字符串，注意这里可以使用 strncpy 或 memcpy
	 * 由于我们知道要复制的字节数，所以用 memcpy 更合适 */
	ft_memcpy(substr, s + start, substr_len);
	substr[substrlen] = '\0';
	return (substr);
}
