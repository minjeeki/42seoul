/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:29:39 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/18 16:04:11 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free_arr(int *arr)
{
	free(arr);
	arr = NULL;
	return (1);
}

int	ft_free_stack(t_deque *stack, int *arr)
{
	if (arr != NULL)
		free(arr);
	free(stack);
	stack = NULL;
	return (1);
}

int	ft_print_error(void)
{
	write(1, "Error\n", 7);
	return (1);
}

void	ft_swap(int *arr, int idx)
{
	int	tmp;

	tmp = 0;
	tmp = arr[idx];
	arr[idx] = arr[idx + 1];
	arr[idx + 1] = tmp;
}

// 디버깅을 위해 사용했던 함수 (제출 전에 삭제 필요)
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
