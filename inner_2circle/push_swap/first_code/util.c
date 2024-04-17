/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:29:39 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/17 17:38:39 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free_arr(int *arr)
{
	free(arr);
	return (1);
}

int	ft_free_stack(t_deque *stack, int *arr)
{
	if (arr != NULL)
		free(arr);
	free(stack);
	return (1);
}

int	ft_print_error(void)
{
	write(1, "Error\n", 7);
	return (1);
}
