/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:58:00 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/18 13:39:15 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*input_arr;
	t_deque	*stack_a;

	input_arr = (int *)malloc((argc - 1) * sizeof(int));
	if (input_arr == NULL)
		return (1);
	if (ft_check_validate_n_normalize(argc, argv, input_arr) == 1)
		return (ft_free_arr(input_arr));
	ft_print_arr(argc, input_arr);
	return (0);
}
