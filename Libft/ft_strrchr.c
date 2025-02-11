#include "libft.h"
char	*ft_strrchr(const char *s, int c)
{
	const char	*last;
	size_t		i;

	last = NULL;/* 记录最后一次匹配的位置 */
	i = 0;
	while (1)
	{
		if (s[i] == (char)c)/* 检查当前字符是否匹配 */
			last = s + i;/* 更新最后一次匹配的位置 */
		if (s[i] == '\0')/* 检查是否到字符串末尾 */
			break ;
		i++;
	}
	/* 如果 c 是 '\0'，返回空字符的地址 */
	if ((char)c == '\0')
		return ((char *)(s + i));
	return ((char *)last);/* 返回最后一次匹配的地址（或 NULL）*/
}
