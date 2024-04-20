/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:58:00 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/20 21:35:50 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*input_arr;
	t_list	stack_a;
	t_list	stack_b;

	input_arr = (int *)malloc((argc - 1) * sizeof(int));
	if (input_arr == NULL)
		return (1);
	if (ft_check_validate_n_normalize(argc, argv, input_arr) == 1)
		return (ft_free_arr(input_arr));
	if (ft_init_n_copy(&stack_a, &stack_b, argc, input_arr) == 1)
		return (1);
	return (!ft_free_stack(&stack_a) || !ft_free_stack(&stack_b));
}
