/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 03:28:52 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/29 03:52:32 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_init_stack(t_list *stack);
int		ft_copy_arr_to_linked_list(t_list *stack, int argc, int *input_arr);
void	ft_insert_list(t_list *stack, int is_at_head, t_node *input_node);
t_node	*ft_delete_list(t_list *stack, int is_at_head);

int	ft_init_n_copy(t_list *stack_a, t_list *stack_b, int size_arr, int *arr)
{
	if (ft_init_stack(stack_a) == 1)
		return (ft_free_int_arr(arr));
	if (ft_init_stack(stack_b) == 1)
		return (ft_free_int_arr(arr) && ft_free_stack(stack_a));
	if (ft_copy_arr_to_linked_list(stack_a, size_arr, arr) == 1)
		return (ft_free_int_arr(arr) && ft_free_stack(stack_b));
	return (!ft_free_int_arr(arr));
}

int	ft_init_stack(t_list *stack)
{
	stack -> head = (t_node *)malloc(sizeof(t_node));
	if (stack -> head == NULL)
	{
		stack = NULL;
		return (1);
	}
	stack -> head -> left = NULL;
	stack -> head -> right = NULL;
	stack -> tail = (t_node *)malloc(sizeof(t_node));
	if (stack -> tail == NULL)
		return (ft_free_stack(stack));
	stack -> head -> right = stack -> tail;
	stack -> tail -> left = stack -> head;
	stack -> tail -> right = NULL;
	stack -> size = 0;
	return (0);
}

int	ft_copy_arr_to_linked_list(t_list *stack, int size_arr, int *input_arr)
{
	int		idx;
	t_node	*new_node;
	// int		size_str;

	idx = 0;
	// size_str = ft_count_max_size(argc - 1);
	while (idx < size_arr)
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		if (new_node == NULL)
			return (ft_free_stack(stack));
		new_node -> data = input_arr[idx];
		// new_node -> binary_str = ft_convert_binary(size_str, new_node);
		// if (new_node -> binary_str == NULL)
		//	return (1);
		idx++;
		new_node -> left = stack -> tail -> left;
		new_node -> right = stack -> tail;
		stack -> tail -> left -> right = new_node;
		stack -> tail -> left = new_node;
		(stack -> size)++;
	}
	return (0);
}

void	ft_insert_list(t_list *stack, int is_at_head, t_node *input_node)
{
	if (is_at_head == 1)
	{
		input_node -> left = stack -> head;
		input_node -> right = stack -> head -> right;
		stack -> head -> right -> left = input_node;
		stack -> head -> right = input_node;
	}
	else
	{
		input_node -> right = stack -> tail;
		input_node -> left = stack -> tail -> left;
		stack -> tail -> left -> right = input_node;
		stack -> tail -> left = input_node;
	}
	(stack -> size)++;
}

t_node	*ft_delete_list(t_list *stack, int is_at_head)
{
	t_node	*deleted_node;

	if (is_at_head == 1)
	{
		deleted_node = stack -> head -> right;
		stack -> head -> right = deleted_node -> right;
		deleted_node -> right -> left = stack -> head;
	}
	else
	{
		deleted_node = stack -> tail -> left;
		stack -> tail -> left = deleted_node -> left;
		deleted_node -> left -> right = stack -> tail;
	}
	deleted_node -> left = NULL;
	deleted_node -> right = NULL;
	(stack -> size)--;
	return (deleted_node);
}
