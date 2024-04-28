/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 04:38:21 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/29 06:42:12 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_list *stack_a)
{
	int	max_bits;
	int	max;

	max = (stack_a -> size) - 1;
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list *stack_a, t_list *stack_b)
{
	int	bit;
	int	max_bits;
	int	size;
	int	idx;

	bit = 0;
	max_bits = get_max_bits(stack_a);
	size = stack_a -> size;
	while (bit < max_bits)
	{
		idx = 0;
		while (idx < size)
		{
			if (((stack_a -> head -> right -> data >> bit) & 1) == 1)
				cmd_rotate(stack_a, 'a');
			else
				cmd_push(stack_a, stack_b, 'a');
			idx++;
		}

		while (stack_b -> size != 0)
			cmd_push(stack_b, stack_a, 'b');
		bit++;
	}
}
