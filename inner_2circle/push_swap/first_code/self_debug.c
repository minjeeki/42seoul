/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:56:42 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/20 18:42:38 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_arr(int argc, int *input_arr)
{
	int	idx;

	idx = 0;
	while (idx < argc - 1)
	{
		printf("%d ", input_arr[idx]);
		idx++;
	}
	printf("\n");
}

void	ft_print_stack(t_list *stack)
{
	stack -> cur = stack -> head -> right;
	while (stack -> cur != stack -> tail)
	{
		printf("%d ", stack -> cur -> data);
		stack -> cur = stack -> cur -> right;
	}
}

// main 함수 시작 위치에 atexit(check_leak); 문장 추가
void	check_leak(void)
{
	system("leaks a.out");
}
