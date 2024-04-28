/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:10:16 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/28 22:38:48 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 버블 정렬 내부에서 자리 바꿈 관련 코드
void	ft_swap(int *arr, int idx)
{
	int	tmp;

	tmp = 0;
	tmp = arr[idx];
	arr[idx] = arr[idx + 1];
	arr[idx + 1] = tmp;
}
