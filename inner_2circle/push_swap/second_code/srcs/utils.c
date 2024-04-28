/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:46:13 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/29 03:40:36 by minjeeki         ###   ########seoul.kr  */
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
int	ft_free_int_arr(int *int_arr)
{
	free(int_arr);
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
	write(1, "Error\n", 6);
	return (1);
}
