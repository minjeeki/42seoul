
#include"libft.h"

/**
 * - Description:
 * Counts the number of nodes in a list.
 *
 * - Parameters:
 * lst: The beginning of the list.
 *
 * - Return value:
 * The length of the list.
**/

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	if (!lst)
		return (0);
	i = 0;
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}