/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:10:16 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/28 22:10:30 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *arr, int idx)
{
	int	tmp;

	tmp = 0;
	tmp = arr[idx];
	arr[idx] = arr[idx + 1];
	arr[idx + 1] = tmp;
}
