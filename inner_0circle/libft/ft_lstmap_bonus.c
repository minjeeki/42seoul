/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:39:31 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/30 21:36:39 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;
	void	*tmp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new = NULL;
	while (lst != NULL)
	{
		tmp = f(lst->content);
		node = ft_lstnew(tmp);
		if (node == NULL)
		{
			ft_lstclear(&new, del);
			del(tmp);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst -> next;
	}
	return (new);
}
