/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 04:38:21 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/30 02:30:55 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
