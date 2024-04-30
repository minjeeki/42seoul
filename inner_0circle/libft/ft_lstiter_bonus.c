/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:36:53 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/30 18:03:14 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*cur;

	if (lst == NULL || f == NULL)
		return ;
	cur = lst;
	while (cur != NULL)
	{
		f(cur -> content);
		cur = cur -> next;
	}	
}
