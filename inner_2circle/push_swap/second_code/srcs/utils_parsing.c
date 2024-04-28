/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:14:50 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/28 20:19:17 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size_str(char *str)
{
	int	size_str;

	if (ft_strchr(str, ' ') == NULL)
		size_str = ft_strlen(str);
	else
		size_str = (char *)ft_strchr(str, ' ') - str;
	return (size_str);
}

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
