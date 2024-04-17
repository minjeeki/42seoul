/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:29:29 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/17 18:03:03 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_safe_atoi(char *str, int *arr_mem);
int		ft_convert_to_int_and_check_sorted(int argc, char *argv[], int *arr);
void	ft_copy_arr_and_bubble_sort(int argc, int *origin_arr, int *sorted_arr);
int		ft_check_dup_and_normalize(int argc, int *origin_arr, int *sorted_arr);

int	ft_check_validate_and_normalize(int argc, char *argv[], int *origin_arr)
{
	int	*sorted_arr;

	if (ft_convert_to_int_and_check_sorted(argc, argv, origin_arr) == 1)
		return (1);
	sorted_arr = (int *)malloc(argc * sizeof(int));
	if (sorted_arr == NULL)
		return (1);
	ft_copy_arr_and_bubble_sort(argc, origin_arr, sorted_arr);
	if (ft_check_dup_and_normalize(argc, origin_arr, sorted_arr) == 1)
		return (ft_free_arr(sorted_arr));
	free(sorted_arr);
	return (0);
}

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

int	ft_convert_to_int_and_check_sorted(int argc, char *argv[], int *arr)
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

void	ft_copy_arr_and_bubble_sort(int argc, int *origin_arr, int *sorted_arr)
{
	int	idx1;
	int	idx2;
	int	tmp;

	idx1 = 0;
	while (idx1 < argc)
	{
		sorted_arr[idx1] = origin_arr[idx1];
		idx1++;
	}
	idx1 = 0;
	while (idx1 < argc - 1)
	{
		idx2 = 0;
		while (idx2 < argc - 1 - idx1)
		{
			if (sorted_arr[idx2] > sorted_arr[idx2 + 1])
			{
				tmp = sorted_arr[idx2];
				sorted_arr[idx2] = sorted_arr[idx2 + 1];
				sorted_arr[idx2 + 1] = tmp;
			}
			idx2++;
		}
		idx1++;
	}
}

int	ft_check_dup_and_normalize(int argc, int *origin_arr, int *sorted_arr)
{
	int	idx_origin;
	int	idx_sorted;

	idx_sorted = 1;
	while (idx_sorted < argc - 1)
	{
		if (sorted_arr[idx_sorted] == sorted_arr[idx_sorted - 1])
			return (1);
		idx_sorted++;
	}
	idx_origin = 0;
	while (idx_origin < argc)
	{
		idx_sorted = 0;
		while (idx_sorted < argc)
		{
			if (origin_arr[idx_origin] == sorted_arr[idx_sorted])
				break ;
			idx_sorted++;
		}
		origin_arr[idx_origin] = idx_sorted;
		idx_origin++;
	}
	return (0);
}
