#include "libft.h"
#include <stdlib.h>
#include <stddef.h>
/* 辅助函数：检查字符是否是分隔符 */
static int	is_separator(char c, char sep)
{
	return (c == sep);
}
/* 计算子字符串的数量 */
static size_t	count_substrings(char const *s, char sep)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		/* 跳过分隔符 */
		while (*s != '\0' && is_separator(*s, sep))
			s++;
		/* 如果不是结束符，说明是一个新的子字符串 */
		if (*s)
		{
			count++;
			/* 跳过当前子字符串的字符 */
			while (*s && !is_separator(*s, sep))
				s++;
		}
	}
	return (count);
}
/* 释放 ft_split 函数分配的内存 */
void	free_split(char **result)
{
	size_t	i;

	if (!result)
		return ;
	/* 逐个释放每个子字符串 */
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);/* 最后释放指向字符串数组的指针 */
}
/* 将字符串 s 按照字符 sep 分割，返回一个字符串数组 */
char	**ft_split(char const *s, char c)
{
	size_t	num_substrings;
	size_t	i;
	size_t	start;
	size_t	len;
	char	**result;

	if (!s)
		return (NULL);
	/* 计算子字符串的数量 */
	num_substrings = count_substrings(s, c);
	/* 分配存放子字符串的数组 */
	result = malloc((num_substrings + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	while (*s)
	{
		/* 跳过分隔符 */
		while (*s && is_separator(*s, c))
			s++;
		/* 如果不是结束符，说明是一个新的子字符串 */
		if (*s)
		{
			start = s - s;  /* 当前子字符串的开始位置 */
			/* 跳过子字符串，找到下一个分隔符或字符串结尾 */
			len = 0;
			while (s[len] && !is_separator(s[len], c))
				len++;
			result[i] = ft_substr(s, 0, len);/* 使用 ft_substr 提取子字符串 */
			if (!result[i])
			{
				free_split(result);
				return (NULL);
			}
			i++;
			s += len;
		}
	}
	result[i] = NULL;
	return (result);
}
