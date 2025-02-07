#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
/* 查找换行符 */
static char	*find_newline(char *str)
{
	while (str && *str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}
/* 读取文件并拼接到stash */
static char	*read_and_store(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*temp;

	while (!find_newline(stash))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0) /* 读取完成或错误 */
			return (stash);
		buffer[bytes_read] = '\0';
		temp = stash;
		stash = ft_strjoin(stash, buffer);
		free(temp);
		if (!stash)
			return (NULL);
	}
	return (stash);
}
/* 获取一行数据 */
char	*get_next_line(int fd)
{
	static char	*stash;/* 静态变量，存储上次 `read` 未使用完的数据 */
	char		*line;
	char		*new_stash;
	ssize_t		line_length;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_store(fd, stash);
	if (!stash)
		return (NULL);
	line_length = find_newline(stash) - stash;
	line = ft_substr(stash, 0, line_length); /* 提取完整的一行 */
	new_stash = ft_substr(stash, line_length, ft_strlen(stash) - line_length);/* 复制剩余部分 */
	free(stash);
	stash = new_stash;
	return (line);
}
