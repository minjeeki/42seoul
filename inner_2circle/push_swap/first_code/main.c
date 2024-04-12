/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:58:00 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/12 20:27:36 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_deque	*stack_a;
	t_deque	*stack_b;

	stack_a = ft_validate_arg(argc, argv);
	ft_is_sorted(stack_a, argc);
	stack_b = malloc(sizeof(t_deque));
	if (stack_b == NULL)
	{
		free(stack_a -> arr);
		free(stack_a);
		exit(1);
	}
	return (0);
}

t_deque	*ft_validate_arg(int argc, char *argv)
{
	t_deque		*stack_a;
	int			idx;
	long long	conversion;

	if (argc < 2)
		exit(1);
	stack_a = malloc(sizeof(t_deque));
	if (stack_a == NULL)
		exit(1);
	stack_a -> arr = (int *)malloc(argc * sizeof(int));
	if (stack_a -> arr == NULL)
	{
		free(stack_a);
		exit(1);
	}
	idx = 1;
	while (idx <= argc)
	{
		conversion = ft_strtol(argv[idx], 10);
		if (conversion < INT_MIN || conversion > INT_MAX)
		{
			free(stack_a -> arr);
			free(stack_a);
			write(1, "Error\n", 7);
			exit(1);
		}
		idx++;
	}
	return (stack_a);
}
long long	ft_strtol(char *converted, int digit)
{
	long long	num;
	// 변환될 수 없는 값을 갖고 있을 경우 INT_MIN - 1 값을 갖게끔 처리할 것
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
		free(stack_a);
		exit(1);
	}
}
