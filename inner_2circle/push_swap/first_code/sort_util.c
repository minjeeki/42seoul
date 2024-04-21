/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:54:27 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/21 17:02:19 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list *stack)
{
	stack -> cur = stack -> head -> right;
	while (stack -> cur -> right != NULL)
	{
		if (stack -> cur -> data > stack -> cur -> right -> data)
			return (0);
		stack -> cur = stack -> cur -> right;
	}
	return (1);
}
