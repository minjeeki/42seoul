/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:19:29 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/22 22:03:04 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_radix(t_list *stack_a, t_list *stack_b, int argc)
{
	int	size_binary;
	int	idx_str;
	int cnt_stack_a;

	size_binary = ft_count_max_size(argc - 1);
	idx_str = size_binary;
	while (idx_str >= 0)
	{
		cnt_stack_a = 0;
		while (cnt_stack_a < (argc - 1))
		{
			printf("현재 확인할 노드의 이진수 : %s\n", stack_a -> head -> right -> binary_str);			
			printf("1 사이클 내 노드 확인 횟수 : %d\n", cnt_stack_a);
			if (stack_a -> head -> right -> binary_str[idx_str] == '1')
				cmd_rotate(stack_a, 'a');
			else
			{
				cmd_push(stack_a, stack_b, 'a');
				if (stack_b -> size != 0)
					cmd_rotate(stack_b, 'b');
				stack_b -> size++;
				stack_a -> size--;
			}
			cnt_stack_a++;
		}
		while (stack_b -> size != 0)
		{
			cmd_push(stack_b, stack_a, 'b');
			stack_b -> size--;
			stack_a -> size++;
		}
		idx_str--;
	}
}
