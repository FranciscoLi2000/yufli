#include "libft.h"
#include <stdlib.h>
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*last;

	new_lst = NULL;
	last = NULL;
	while (lst)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
		{
			if (del)
				ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_node->content = f(lst->content);
		new_node->next = NULL;
		if (last)
			last->next = new_node;
		else
			new_lst = new_node;
		last = new_node;
		lst = lst->next;
	}
	return (new_lst);
}
