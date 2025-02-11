#include "libft.h"
#include <stdlib.h>
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;/* 保存下一个节点的地址 */
		if (del != NULL)
			del(current->content);/* 释放节点内容 */
		free(current);/* 释放节点本身 */
		current = next;/* 移动到下一个节点 */
	}
	*lst = NULL;/* 将头指针置为 NULL */
}
