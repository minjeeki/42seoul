/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:58:55 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/29 03:38:05 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_int_arr(int *origin_arr, int size_arr)
{
	int	idx;

	idx = 0;
	printf("---정수 배열 요소 출력 시작---\n");
	while (idx < size_arr)
	{
		printf("%d의 값 : %d\n", idx, origin_arr[idx]);
		idx++;
	}
	printf("---정수 배열 요소 출력 종료---\n");
}

void	ft_print_str_arr(char	**origin_arr)
{
	int	idx;

	idx = 0;
	printf("---문자열 배열 요소 출력 시작---\n");
	while (origin_arr[idx] != NULL)
	{
		printf("%d의 값 : %s\n", idx, origin_arr[idx]);
		idx++;
	}
	printf("---문자열 배열 요소 출력 종료---\n");
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
	system("leaks push_swap");
}
