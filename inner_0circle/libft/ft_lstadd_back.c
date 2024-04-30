
#include"libft.h"

/**
 * - Description:
 * Adds the node 'new' at the end of the list.
 *
 * - Parameters:
 * lst: The address of a pointer to the first link of a list.
 * new: The address of a pointer to the node to be added to the list.
 *
 * - Return value:
 * Node
**/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
}