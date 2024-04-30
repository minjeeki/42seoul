
#include"libft.h"

/**
 * - Description:
 * Iterates the list 'lst' and applies the function 'f' on the content
 * of each node.
 *
 * - Parameters:
 * lst: The address of a pointer to a node.
 * f: The address of the function used to iterate on the list.
 *
 * - Return value:
 * None
**/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = lst;
	while (temp != NULL)
	{
		(*f)(temp->content);
		temp = temp->next;
	}
}