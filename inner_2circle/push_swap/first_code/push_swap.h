/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:58:28 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/17 17:39:26 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <unistd.h>
# include <stdlib.h>

// 구조체 배열의 dequeue
typedef struct s_deque{
	int	*arr;
	int	top;
	int	bottom;
}	t_deque;

int	ft_check_validate_and_normalize(int argc, char *argv[], int *origin_arr);
int	ft_free_stack(t_deque *stack, int *arr);
int	ft_free_arr(int *arr);
int	ft_print_error(void);

#endif