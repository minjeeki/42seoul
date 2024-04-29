/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:46:13 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/30 04:52:02 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// parsing.c에서 split을 할 때 사용한 문자열 배열 할당 해제 시 사용하는 함수
int	ft_free_str_arr(char **str_arr)
{
	int	idx;

	idx = 0;
	while (str_arr[idx] != NULL)
	{
		free(str_arr[idx]);
		idx++;
	}
	free(str_arr);
	return (1);
}

// origin_arr, sorted_arr 등 정수형 배열을 할당 해제, 1 반환 시 사용하는 함수
int	ft_free_int_arr(int *int_arr)
{
	free(int_arr);
	return (1);
}

// stack_a 와 stack_b 할당 해제 시 사용하는 함수
int	ft_free_stack(t_list *stack)
{
	t_node	*tmp;
	t_node	*cur;

	if (stack == NULL)
		return (0);
	cur = stack -> head;
	while (cur != NULL)
	{
		tmp = cur;
		if (tmp -> binary_str != NULL)
			free(tmp -> binary_str);
		cur = tmp -> right;
		free(tmp);
	}
	stack -> head = NULL;
	stack -> tail = NULL;
	stack -> size = 0;
	stack = NULL;
	free(stack);
	return (1);
}

// 정수형으로 변환 불가능한 인자, 중복된 요소가 있을 경우 출력하는 에러 문구
int	ft_print_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

// 십진수를 이진수로 변환할 때 이진수의 크기를 모두 맞춰야 하기에 가장 큰 값을 기준으로 자릿수 구함
int	get_max_bits(int max_num)
{
	int	count;

	count = 0;
	while (max_num > 0)
	{
		count++;
		max_num /= 2;
	}
	return (count);
}
