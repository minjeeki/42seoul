/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:14:50 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/28 21:23:55 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 공백 문자로 구분한 문자열 내부의 문자열의 길이 확인 (문자 ~ 공백 문자 또는 문자 ~ 문자열 끝 확인)
int	ft_size_str(char *str)
{
	int	size_str;

	if (ft_strchr(str, ' ') == NULL)
		size_str = ft_strlen(str);
	else
		size_str = (char *)ft_strchr(str, ' ') - str;
	return (size_str);
}

// 문자열 중 int형으로 변환 가능한지 판단 후 int형으로 변환 (변환 불가 항목에 대해 Error 처리)
int	ft_safe_atoi(char *str, int *arr_mem, int idx_arr)
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
	arr_mem[idx_arr] = (int)(num * sign);
	return (0);
}

// 문자열 내에 공백 문자를 기준으로 나눌 수 있는 문자열의 개수가 몇개인지 확인하는 함수
int	ft_count_str_elem(char *str)
{
	int	idx;
	int	is_char;
	int	count;

	idx = 0;
	is_char = 0;
	if (str[idx] != ' ' && str[idx] != '\0')
		is_char = 1;
	count = 0;
	while (str[idx] != '\0')
	{
		if (is_char == 0 && str[idx] != ' ')
			is_char = 1;
		else if (is_char == 1 && str[idx] == ' ')
		{
			is_char = 0;
			count++;
		}
		idx++;
	}
	if (is_char == 1)
		count++;
	return (count);
}
