/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:58:00 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/17 18:05:52 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		*input_arr;
	t_deque	*stack_a;

	if (argc < 2)
		return (1);
	input_arr = (int *)malloc(argc * sizeof(int));
	if (input_arr == NULL)
		return (1);
	if (ft_check_validate_and_normalize(argc, argv, input_arr) == 1)
		ft_free_arr(input_arr);
	
	int idx = 0;
	while (idx < argc - 1)
	{
		printf("%d ", input_arr[idx]);
		idx++;
	}
	printf("\n");
	return (0);
}