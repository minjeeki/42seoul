/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_binary_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:35:15 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/22 22:04:01 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_max_size(int max_n)
{
	int	cnt;

	cnt = 0;
	while (max_n > 0)
	{
		cnt++;
		max_n >>= 1;
	}
	return (cnt);
}

char	*ft_convert_binary(int size_str, t_node *new_node)
{
	int		idx;
	int		n;
	char	*res;

	n = new_node -> data;
	res = (char *)malloc((size_str) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[size_str] = '\0';
	idx = size_str - 1;
	while (n > 0 && idx >= 0)
	{
		res[idx] = (n % 2) + '0';
		n /= 2;
		idx--;
	}
	while (idx >= 0)
	{
		res[idx] = '0';
		idx--;
	}
	return (res);
}
