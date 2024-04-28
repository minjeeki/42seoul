/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 05:01:27 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/29 06:13:54 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_distance(t_list *stack, int min);
void	sort_3(t_list *stack_a);
void	sort_4(t_list *stack_a, t_list *stack_b);
//void	sort_5(t_list *stack_a, t_list *stack_b);

void	simple_sort(t_list *stack_a, t_list *stack_b)
{
	int	size;

	size = stack_a -> size;
	if (size == 2)
		cmd_swap(stack_a, 'a');
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	// else if (size == 5)
	// 	sort_5(stack_a, stack_b);
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
			break;
		distance++;
		cur = cur -> right;
	}
	return (distance);
}

void	sort_3(t_list *stack_a)
{
	t_node	*cur;

	cur = stack_a -> head -> right;
	if (cur -> data == 0)
	{
		cmd_reverse_rotate(stack_a, 'a');
		cmd_swap(stack_a, 'a');
	}
	else if (cur -> data == 1)
	{
		if (cur -> right -> data == 0)
			cmd_swap(stack_a, 'a');
		else
			cmd_reverse_rotate(stack_a, 'a');
	}
	else if (cur -> data == 2)
	{
		if (cur -> right -> data == 0)
			cmd_rotate(stack_a, 'a');
		else
		{
			cmd_swap(stack_a, 'a');
			cmd_reverse_rotate(stack_a, 'a');
		}
	}
}

void	sort_4(t_list *stack_a, t_list *stack_b)
{
	int	min_distance;

	min_distance = ft_get_distance(stack_a, 0);
	if (min_distance == 1)
		cmd_swap(stack_a, 'a');
	else if (min_distance == 2)
	{
		cmd_rotate(stack_a, 'a');
		cmd_rotate(stack_a, 'a');
	}
	else if (min_distance == 3)
		cmd_reverse_rotate(stack_a, 'a');
	cmd_push(stack_a, stack_b, 'a');
	sort_3(stack_a);
	cmd_push(stack_b, stack_a, 'b');
}
