/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 02:48:01 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/30 04:01:55 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min(t_list *stack, int at_least)
{
	t_node	*cur;
	int		res;

	cur = stack -> head -> right;
	res = INT_MAX;
	while (cur -> right != NULL)
	{
		if ((cur -> data < res) && (cur -> data > at_least))
			res = cur -> data;
		cur = cur -> right;
	}
	return (res);
}

int	ft_get_distance(t_list *stack, int min)
{
	t_node	*cur;
	int		distance;

	distance = 0;
	cur = stack -> head -> right;
	while (cur -> right != NULL)
	{
		if (cur -> data == min)
			break ;
		distance++;
		cur = cur -> right;
	}
	return (distance);
}

void	ft_repeat_rotate(t_list *stack_a, int is_reverse)
{
	if (is_reverse == 0)
	{
		cmd_rotate(stack_a, 'a');
		cmd_rotate(stack_a, 'a');
	}
	else
	{
		cmd_reverse_rotate(stack_a, 'a');
		cmd_reverse_rotate(stack_a, 'a');
	}
}
