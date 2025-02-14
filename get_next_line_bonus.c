#include "get_next_line_bonus.h"
/* 查找或创建对应fd的节点 */
static t_list	*get_fd_node(t_list **head, int fd)
{
	t_list	*current;
	t_list	*prev;
	t_list	*new_node;

	current = *head;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		prev = current;
		current = current->next;
	}
	/* 未找到，创建新节点 */
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->stash = NULL;
	new_node->next = NULL;
	if (prev)
		prev->next = new_node;
	else
		*head = new_node;
	return (new_node);
}
static char	*read_and_store(int fd, char *stash)
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
static char	*extract_line(char *stash)
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
static char	*save_remaining(char *stash)
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
static void	free_fd_node(t_list **head, int fd)
{
	t_list	*current;
	t_list	*prev;

	current = *head;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (prev)
				prev->next = current->next;
			else
				*head = current->next;
			free(current->stash);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list	*node;
	char	*line;

	head = NULL; /* 静态链表头 */
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = get_fd_node(&head, fd);
	if (!node)
		return (NULL);
	node->stash = read_and_store(fd, node->stash);
	if (!node->stash)
	{
		free_fd_node(&head, fd);
		return (NULL);
	}
	line = extract_line(node->stash);
	node->stash = save_remaining(node->stash);
	if (!node->stash)
		free_fd_node(&head, fd);
	return (line);
}
