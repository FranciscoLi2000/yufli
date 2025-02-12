#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
char	*read_and_store(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr(stash, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (bytes_read < 0)
		return (NULL);
	return (stash);
}
char	*extract_line(char *stash)
{
	char	*line;
	int	i;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_substr(stash, 0, i + 1);
	return (line);
}
char	*save_remaining(char *stash)
{
	char	*remaining;
	int	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	remaining = ft_strdup(stash + i + 1);
	free(stash);
	return (remaining);
}
char	*get_next_line(int fd)
{
	static char	*stash[FD_MAX];
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
		return (NULL);
	stash[fd] = read_and_store(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = save_remaining(stash[fd]);
	return (line);
}
