/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:08:01 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/28 22:34:55 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*origin_arr;
	int	size_arr;

	size_arr = ft_parsing(argc, argv, &origin_arr);
	if (size_arr <= 0)
		return (1);
	if (ft_check_condition_and_normalize(&origin_arr, size_arr) == 1)
		return (1);
	ft_print_int_arr(origin_arr, size_arr);
	return (0);
}
