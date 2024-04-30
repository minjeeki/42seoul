/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 02:48:01 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/30 04:36:23 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 스택 내에서 at_least보다 큰, 최솟값을 구하는 함수
int	ft_get_min(t_list *stack, int at_least)
{
	t_node	*cur;
	int		res;

	cur = stack -> head -> right;
	res = INT_MAX;
	while (cur -> right != NULL)
	{
		if ((cur -> data < res) && (cur -> data > at_least))
			res = cur -> data;
		cur = cur -> right;
	}
	return (res);
}

// 스택 내에서 특정 노드 (주로 최솟값)의 top으로부터의 거리를 구하는 함수
int	ft_get_distance(t_list *stack, int min)
{
	t_node	*cur;
	int		distance;

	distance = 0;
	cur = stack -> head -> right;
	while (cur -> right != NULL)
	{
		if (cur -> data == min)
			break ;
		distance++;
		cur = cur -> right;
	}
	return (distance);
}

// simple_sort 중 sort_5 함수의 줄 수를 줄이기 위해 만든 함수
void	ft_repeat_rotate(t_list *stack_a, int is_reverse)
{
	if (is_reverse == 0)
	{
		cmd_rotate(stack_a, 'a');
		cmd_rotate(stack_a, 'a');
	}
	else
	{
		cmd_reverse_rotate(stack_a, 'a');
		cmd_reverse_rotate(stack_a, 'a');
	}
}

// sort_3 함수에서 이미 정렬이 완료된 상태의 경우 추가 작업을 하지 않게 하기 위해 만든 함수
int	ft_is_ascend(t_list *stack)
{
	int		idx;
	t_node	*cur;

	if (stack -> size < 2)
		return (1);
	cur = stack -> head -> right -> right;
	while (cur -> right != NULL)
	{
		if (cur -> data < cur -> left -> data)
			return (0);
		cur = cur -> right;
	}
	return (1);
}
