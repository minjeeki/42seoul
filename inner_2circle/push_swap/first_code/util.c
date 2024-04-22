/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:29:39 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/22 17:34:37 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free_arr(int *arr)
{
	free(arr);
	arr = NULL;
	return (1);
}

int	ft_free_stack(t_list *stack)
{
	t_node	*tmp;

	if (stack == NULL)
		return (0);
	stack -> cur = stack -> head;
	while (stack -> cur != NULL)
	{
		tmp = stack -> cur;
		stack -> cur = tmp -> right;
		free(tmp);
	}
	stack -> head = NULL;
	stack -> cur = NULL;
	stack -> tail = NULL;
	stack -> size = 0;
	stack = NULL;
	return (1);
}

int	ft_print_error(void)
{
	write(1, "Error\n", 7);
	return (1);
}

void	ft_swap(int *arr, int idx)
{
	int	tmp;

	tmp = 0;
	tmp = arr[idx];
	arr[idx] = arr[idx + 1];
	arr[idx + 1] = tmp;
}
