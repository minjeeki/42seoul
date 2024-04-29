/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:08:01 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/30 02:46:25 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list *stack_a, t_list *stack_b);

int	main(int argc, char *argv[])
{
	int		*origin_arr;
	int		size_arr;
	t_list	stack_a;
	t_list	stack_b;

	atexit(check_leak);
	size_arr = ft_parsing(argc, argv, &origin_arr);
	if (size_arr <= 0)
		return (1);
	if (ft_check_condition_and_normalize(&origin_arr, size_arr) == 1)
		return (ft_free_int_arr(origin_arr));
	if (ft_init_n_copy(&stack_a, &stack_b, size_arr, origin_arr) == 1)
		return (1);
	sort_stack(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}

void	sort_stack(t_list *stack_a, t_list *stack_b)
{
	if (stack_a -> size <= 4)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b, stack_a -> size);
}
