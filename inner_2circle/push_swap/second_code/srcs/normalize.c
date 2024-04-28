/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:26:15 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/28 23:55:09 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_sorted(int *int_arr, int size);
int		ft_is_duplicated(int *int_arr, int size);
void	ft_copy_n_bubble_sort(int *origin_arr, int *sorted_arr, int size);
void	ft_normalize(int *origin_arr, int *sorted_arr, int size);

int	ft_check_condition_and_normalize(int **origin_arr, int size)
{
	int	*sorted_arr;

	if (ft_is_sorted(*origin_arr, size) || ft_is_duplicated(*origin_arr, size))
		return (1);
	sorted_arr = (int *)malloc(size * sizeof(int));
	if (sorted_arr == NULL)
		return (1);
	ft_copy_n_bubble_sort(*origin_arr, sorted_arr, size);
	ft_normalize(*origin_arr, sorted_arr, size);
	free(sorted_arr);
	return (0);
}

// 초기화 상태의 int 배열이 정렬된 상태인지 확인
int	ft_is_sorted(int *int_arr, int size)
{
	int	idx;

	if (size < 2)
		return (1);
	idx = 1;
	while (idx < size)
	{
		if (int_arr[idx] < int_arr[idx - 1])
			return (0);
		idx++;
	}
	return (1);
}

// int 배열에 중복이 존재하는지 확인
int	ft_is_duplicated(int *int_arr, int size)
{
	int	idx1;
	int	idx2;

	idx1 = 0;
	while (idx1 < size)
	{
		idx2 = idx1 + 1;
		while (idx2 < size)
		{
			if (int_arr[idx1] == int_arr[idx2])
				return (1);
			idx2++;
		}
		idx1++;
	}
	return (0);
}

// sorted_arr에 origin_arr의 값을 복사한 뒤 버블 정렬로 정렬 진행
void	ft_copy_n_bubble_sort(int *origin_arr, int *sorted_arr, int size)
{
	int	idx1;
	int	idx2;

	idx1 = 0;
	while (idx1 < size)
	{
		sorted_arr[idx1] = origin_arr[idx1];
		idx1++;
	}
	idx1 = 0;
	while (idx1 < size - 1)
	{
		idx2 = 0;
		while (idx2 < size - 1 - idx1)
		{
			if (sorted_arr[idx2] > sorted_arr[idx2 + 1])
				ft_swap(sorted_arr, idx2);
			idx2++;
		}
		idx1++;
	}
}

// origin_arr의 값을 sorted_arr의 인덱스 값으로 재할당하면서 정규화 진행
void	ft_normalize(int *origin_arr, int *sorted_arr, int size)
{
	int	idx_origin;
	int	idx_sorted;

	idx_origin = 0;
	while (idx_origin < size)
	{
		idx_sorted = 0;
		while (idx_sorted < size)
		{
			if (origin_arr[idx_origin] == sorted_arr[idx_sorted])
				break ;
			idx_sorted++;
		}
		origin_arr[idx_origin] = idx_sorted;
		idx_origin++;
	}
}
