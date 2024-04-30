
#include"libft.h"

/**
 * - Description:
 * Return the last node of the list.
 *
 * - Parameters:
 * lst: The beginning of the list.
 *
 * - Return value:
 * Last node of the list.
**/

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}