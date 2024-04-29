/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:58:55 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/30 04:08:33 by minjeeki         ###   ########seoul.kr  */
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
	t_node	*cur;

	cur = stack -> head -> right;
	while (cur != stack -> tail)
	{
		printf("%d ", cur -> data);
		cur = cur -> right;
	}
}

// main 함수 시작 위치에 atexit(check_leak); 문장 추가
void	check_leak(void)
{
	system("leaks push_swap");
}

// visualize tester link : https://windowdong11.github.io/push_swap_visualizer/
// evaluation sheet link : https://file.notion.so/f/f/cae37dae-7359-4f13-a5be-ae07fb235a1b/84663506-92f1-4001-b97b-d23b66e66e21/push_swap_.pdf?id=6bcf9dbb-7df0-44a4-bf07-04c72f62b8c1&table=block&spaceId=cae37dae-7359-4f13-a5be-ae07fb235a1b&expirationTimestamp=1714500000000&signature=i5YwKQHXkuNx1QK7nQQRZbeubXovzqLoe8kI6_KAgso&downloadName=push_swap+%E1%84%91%E1%85%A7%E1%86%BC%E1%84%80%E1%85%A1%E1%84%8C%E1%85%B5.pdf