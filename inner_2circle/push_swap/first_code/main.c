/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:58:00 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/12 20:03:54 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_deque	*stack_a;
	t_deque	*stack_b;

	stack_a = malloc(sizeof(t_deque));
	if (stack_a == NULL)
		return (1);
	stack_b = malloc(sizeof(t_deque));
	ft_validate_arg(argc, argv);
	return (0);
}

void	ft_error(void)
{
	write(1, "Error\n", 7);
	exit(1);
}

void	ft_validate_arg(int argc, char *argv)
{
	if (argc < 2)
		exit(1);
}

void	ft_is_sorted(t_deque *stack_a, int argc)
{
	int	arr_size;
	int	idx;
	int	is_sorted;

	idx = 0;
	is_sorted = 1;
	while (idx < (argc - 2))
	{
		if ((stack_a -> arr[idx]) > (stack_a -> arr[idx+1]))
		{
			is_sorted = 0;
			break;
		}
		idx++;
	}
	if (is_sorted == 1)
	{
		free(stack_a -> arr);
		exit(1);
	}
}
