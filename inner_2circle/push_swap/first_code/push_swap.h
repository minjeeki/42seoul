/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:58:28 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/18 16:03:41 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// ft_safe_atoi에서 유효 범위 확인을 위해 사용한 매크로
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

// malloc, free, write 함수 사용을 위해 필요한 헤더 파일
# include <unistd.h>
# include <stdlib.h>

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

// 디버깅을 위해 사용했던 함수와 헤더 파일 (제출 시 삭제 필요)
# include <stdio.h>
void	ft_print_arr(int argc, int *input_arr);

#endif