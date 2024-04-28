/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:55:17 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/29 06:27:57 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_push(t_list *from_stack, t_list *to_stack, char c);
void	cmd_swap(t_list *stack, char c);
void	cmd_rotate(t_list *stack, char c);
void	cmd_reverse_rotate(t_list *stack, char c);

void	cmd_push(t_list *from_stack, t_list *to_stack, char c)
{
	t_node	*tmp_node;

	if (from_stack -> size < 1)
		return ;
	tmp_node = ft_delete_list(from_stack, 1);
	ft_insert_list(to_stack, 1, tmp_node);
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
	from_stack -> size--;
	to_stack -> size++;
}

void	cmd_swap(t_list *stack, char c)
{
	t_node	*first_node;
	t_node	*second_node;

	if (stack -> size < 2)
		return ;
	first_node = ft_delete_list(stack, 1);
	second_node = ft_delete_list(stack, 1);
	ft_insert_list(stack, 1, first_node);
	ft_insert_list(stack, 1, second_node);
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	cmd_rotate(t_list *stack, char c)
{
	t_node	*tmp_node;

	if (stack -> size < 2)
		return ;
	tmp_node = ft_delete_list(stack, 1);
	ft_insert_list(stack, 0, tmp_node);
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	cmd_reverse_rotate(t_list *stack, char c)
{
	t_node	*tmp_node;

	if (stack -> size < 2)
		return ;
	tmp_node = ft_delete_list(stack, 0);
	ft_insert_list(stack, 1, tmp_node);
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}
