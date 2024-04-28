/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:08:01 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/29 06:09:46 by minjeeki         ###   ########seoul.kr  */
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

	size_arr = ft_parsing(argc, argv, &origin_arr);
	if (size_arr <= 0)
		return (1);
	if (ft_check_condition_and_normalize(&origin_arr, size_arr) == 1)
		return (ft_free_int_arr(origin_arr));
	// ft_print_int_arr(origin_arr, size_arr);
	if (ft_init_n_copy(&stack_a, &stack_b, size_arr, origin_arr) == 1)
		return (1);
	// ft_print_stack(&stack_a);
	sort_stack(&stack_a, &stack_b);
	ft_print_stack(&stack_a);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}

void	sort_stack(t_list *stack_a, t_list *stack_b)
{
	if (stack_a -> size <= 4)
	{
		printf("size가 4 이하이기에 simple_sort를 합니다\n");
		simple_sort(stack_a, stack_b);
	}
	else
	{
		printf("size가 5 이상이기에 radix_sort를 합니다\n");
		radix_sort(stack_a, stack_b);
	}
		
}