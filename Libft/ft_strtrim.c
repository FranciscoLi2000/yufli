#include "libft.h"
#include <stdlib.h>
#include <stddef.h>
/* 辅助函数：检查字符是否在 set 中 */
static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}
/* 去掉字符串 s1 两边的 set 中的字符，返回一个新的字符串 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	/* 计算 s1 的长度 */
	len = ft_strlen(s1);
	/* 1. 找到第一个不在 set 中的字符 */
	start = 0;
	while (s1[start] != '\0' && is_in_set(s1[start], set))
		start++;
	/* 2. 找到最后一个不在 set 中的字符 */
	end = len - 1;
	while (end > start && is_in_set(s1[end], set))
		end--;
	/* 3. 如果 start 超过 end，说明没有有效字符，返回空字符串 */
	if (start > end)
	{
		trimmed = malloc(1);
		if (trimmed)
			trimmed[0] = '\0';
		return (trimmed);
	}
	/* 4. 使用 ft_substr 获取子字符串（从 start 到 end）*/
	return (ft_substr(s1, start, end - start + 1));
}
