/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:12:25 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/30 21:31:35 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*cur;
	int		cnt;

	if (lst == NULL)
		return (0);
	cur = lst;
	cnt = 0;
	while (cur != NULL)
	{
		cnt++;
		cur = cur -> next;
	}
	return (cnt);
}
