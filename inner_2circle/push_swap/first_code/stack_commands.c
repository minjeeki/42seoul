/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:55:17 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/20 20:58:24 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list *from_stack, t_list *to_stack)
{
	t_node	*tmp_node;

	tmp_node = ft_delete_list(from_stack, 1);
	ft_insert_list(to_stack, 1, tmp_node);
}

void	swap(t_list *stack)
{
	t_node	*first_node;
	t_node	*second_node;

	first_node = ft_delete_list(stack, 1);
	second_node = ft_delete_list(stack, 1);
	ft_insert_list(stack, 1, first_node);
	ft_insert_list(stack, 1, second_node);
}

void	rotate(t_list *stack)
{
	t_node	*tmp_node;

	tmp_node = ft_delete_list(stack, 1);
	ft_insert_list(stack, 0, tmp_node);
}

void	reverse_rotate(t_list *stack)
{
	t_node	*tmp_node;

	tmp_node = ft_delete_list(stack, 0);
	ft_insert_list(stack, 1, tmp_node);
}

void	double_rotate(t_list *stack1, t_list *stack2, int is_reverse)
{
	if (is_reverse == 0)
	{
		rotate(stack1);
		rotate(stack2);
	}
	else
	{
		reverse_rotate(stack1);
		reverse_rotate(stack2);
	}
}
