
#include "libft.h"

/**
 * @brief	Adds the node 'new' at the beginning of the list.
 *
 * @param lst	The address of a pointer to the first link of a list.
 * @param new	The address of a pointer to the node to be added.
 * @return	none
 */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}