/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 05:01:27 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/30 03:59:38 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list *stack_a);
void	sort_4(t_list *stack_a, t_list *stack_b);
void	sort_5(t_list *stack_a, t_list *stack_b);

void	radix_sort(t_list *stack_a, t_list *stack_b, int size)
{
	int		idx;
	int		idx_bit;
	char	bit_char;

	idx_bit = get_max_bits(stack_a -> size - 1) - 1;
	while (idx_bit >= 0)
	{
		idx = 0;
		while (idx < size)
		{
			bit_char = stack_a -> head -> right -> binary_str[idx_bit];
			if (bit_char == '1')
				cmd_rotate(stack_a, 'a');
			else if (bit_char == '0')
				cmd_push(stack_a, stack_b, 'b');
			idx++;
		}
		while (stack_b -> size != 0)
			cmd_push(stack_b, stack_a, 'a');
		idx_bit--;
	}
}

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
	else if (size == 5)
		sort_5(stack_a, stack_b);
}

void	sort_3(t_list *stack_a)
{
	int		min;

	min = ft_get_min(stack_a, -1);
	if ((stack_a -> head -> right -> data == min) && !ft_is_ascend(stack_a))
	{
		cmd_reverse_rotate(stack_a, 'a');
		cmd_swap(stack_a, 'a');
	}
	else if (stack_a -> head -> right -> data == min + 1)
	{
		if (stack_a -> head -> right -> right -> data == min)
			cmd_swap(stack_a, 'a');
		else
			cmd_reverse_rotate(stack_a, 'a');
	}
	else if (stack_a -> head -> right -> data == min + 2)
	{
		if (stack_a -> head -> right -> right -> data == min)
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
	int	min;

	min = ft_get_min(stack_a, -1);
	min_distance = ft_get_distance(stack_a, min);
	if (min_distance == 1)
		cmd_swap(stack_a, 'a');
	else if (min_distance == 2)
	{
		cmd_rotate(stack_a, 'a');
		cmd_rotate(stack_a, 'a');
	}
	else if (min_distance == 3)
		cmd_reverse_rotate(stack_a, 'a');
	cmd_push(stack_a, stack_b, 'b');
	sort_3(stack_a);
	cmd_push(stack_b, stack_a, 'a');
}

void	sort_5(t_list *stack_a, t_list *stack_b)
{
	t_node	*cur;
	int		min;
	int		min_distance;

	min = ft_get_min(stack_a, -1);
	min_distance = ft_get_distance(stack_a, min);
	if (min_distance == 1)
		cmd_swap(stack_a, 'a');
	else if (min_distance == 4)
		cmd_reverse_rotate(stack_a, 'a');
	else if (min_distance == 2)
		ft_repeat_rotate(stack_a, 0);
	else if (min_distance == 3)
		ft_repeat_rotate(stack_a, 1);
	cmd_push(stack_a, stack_b, 'b');
	sort_4(stack_a, stack_b);
	cmd_push(stack_b, stack_a, 'a');
}
