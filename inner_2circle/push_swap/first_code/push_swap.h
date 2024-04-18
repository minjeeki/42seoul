/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:58:28 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/18 13:41:27 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

// 구조체 배열의 dequeue
typedef struct s_deque{
	int	*arr;
	int	top;
	int	bottom;
}	t_deque;

// before_sort.c 함수 중 외부 파일에서 사용할 함수
int		ft_check_validate_n_normalize(int argc, char *argv[], int *origin_arr);
// utils.c 함수 중 외부 파일에서 사용할 함수
int		ft_free_stack(t_deque *stack, int *arr);
int		ft_free_arr(int *arr);
int		ft_print_error(void);
void	ft_swap(int *arr, int idx);
void	ft_print_arr(int argc, int *input_arr);

#endif