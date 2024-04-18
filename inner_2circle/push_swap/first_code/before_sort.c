/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:29:29 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/18 16:00:40 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_safe_atoi(char *str, int *arr_mem);
int		ft_convert_to_int_n_check_sorted(int argc, char *argv[], int *arr);
int		ft_copy_n_sort_with_no_dup(int argc, int *origin_arr, int *sorted_arr);
void	ft_normalize(int argc, int *origin_arr, int *sorted_arr);

// before_sort.c 파일의 main 함수 같은 존재 (정렬 전 처리를 모두 담당하는 함수)
int	ft_check_validate_n_normalize(int argc, char *argv[], int *origin_arr)
{
	int	*sorted_arr;

	if (argc == 1)
		return (1);
	if (ft_convert_to_int_n_check_sorted(argc, argv, origin_arr) == 1)
		return (1);
	sorted_arr = (int *)malloc((argc - 1) * sizeof(int));
	if (sorted_arr == NULL)
		return (1);
	if (ft_copy_n_sort_with_no_dup(argc, origin_arr, sorted_arr) == 1)
		return (ft_free_arr(sorted_arr));
	ft_normalize(argc, origin_arr, sorted_arr);
	free(sorted_arr);
	return (0);
}

// 커맨드 라인 인자 문자열을 받아와 변환 후 arr_mem 포인터를 이용해 값 할당 (유효하지 않을 경우 1 반환)
int	ft_safe_atoi(char *str, int *arr_mem)
{
	int			idx;
	int			sign;
	long long	num;

	idx = 0;
	sign = 1;
	num = 0;
	if (str[idx] == '\0')
		return (1);
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while (str[idx] != '\0')
	{
		if (str[idx] < '0' || str[idx] > '9')
			return (ft_print_error());
		num = num * 10 + (str[idx++] - '0');
	}
	if (num * sign < ((long long)INT_MIN) || num * sign > ((long long)INT_MAX))
		return (ft_print_error());
	*arr_mem = (int)(num * sign);
	return (0);
}

// ft_safe_atoi 를 이용해 문자열 인자를 int로 변환, 
int	ft_convert_to_int_n_check_sorted(int argc, char *argv[], int *arr)
{
	int	idx;
	int	is_ascend;

	idx = 1;
	while (idx < argc)
	{
		if (ft_safe_atoi(argv[idx], &arr[idx - 1]) == 1)
			return (1);
		idx++;
	}
	is_ascend = 1;
	if (argc > 2)
	{
		idx = 1;
		while (idx < argc - 1)
		{
			if (arr[idx] < arr[idx - 1])
				is_ascend = 0;
			idx++;
		}
	}
	if (is_ascend == 1)
		return (1);
	return (0);
}

// sorted_arr에 origin_arr의 값을 복사하고 sorted_arr을 bubble_sort로 정렬하기
int	ft_copy_n_sort_with_no_dup(int argc, int *origin_arr, int *sorted_arr)
{
	int	idx1;
	int	idx2;

	idx1 = 0;
	while (idx1 < argc - 1)
	{
		sorted_arr[idx1] = origin_arr[idx1];
		idx1++;
	}
	idx1 = 0;
	while (idx1 < argc - 2)
	{
		idx2 = 0;
		while (idx2 < argc - 2 - idx1)
		{
			if (sorted_arr[idx2] > sorted_arr[idx2 + 1])
				ft_swap(sorted_arr, idx2);
			if (sorted_arr[idx2] == sorted_arr[idx2 + 1])
				return (1);
			idx2++;
		}
		idx1++;
	}
	return (0);
}

// 정렬된 배열 soted_arr을 이용해 중복 확인 & 중복이 없을 경우 origin_arr을 sorted_arr 인덱스 값으로 정규화
void	ft_normalize(int argc, int *origin_arr, int *sorted_arr)
{
	int	idx_origin;
	int	idx_sorted;

	idx_origin = 0;
	while (idx_origin < argc - 1)
	{
		idx_sorted = 0;
		while (idx_sorted < argc - 1)
		{
			if (origin_arr[idx_origin] == sorted_arr[idx_sorted])
				break ;
			idx_sorted++;
		}
		origin_arr[idx_origin] = idx_sorted;
		idx_origin++;
	}
}
