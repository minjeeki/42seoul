/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:46:13 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/29 03:21:04 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free_str_arr(char **str_arr)
{
	int	idx;

	idx = 0;
	while (str_arr[idx] != NULL)
	{
		free(str_arr[idx]);
		idx++;
	}
	free(str_arr);
	return (1);
}

int	ft_print_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}
