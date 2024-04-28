/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:17:03 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/29 05:07:03 by minjeeki         ###   ########seoul.kr  */
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

// standard C library
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
// 최종 제출 시 주석 처리해야 하는 부분
# include <stdio.h>

// 양방향 연결 리스트 t_list와 연결 리스트 노드 t_node의 구조체 서넌
typedef struct s_node
{
	struct s_node	*left;
	int				data;
	char			*binary_str;
	struct s_node	*right;
}	t_node;

typedef struct s_linked_list
{
	t_node	*head;
	t_node	*tail;
	t_node	*cur;
	int		size;
}	t_list;

// self_debug.c (최종 제출 시 주석 처리 필요)
void	ft_print_int_arr(int *origin_arr, int size_arr);
void	ft_print_str_arr(char	**origin_arr);
void	ft_print_stack(t_list *stack);
void	check_leak(void);
// parsing.c
int		ft_parsing(int argc, char *argv[], int **origin_arr);
// utils_parsing.c
int		ft_size_str(char *str);
int		ft_safe_atoi(char *str, int *arr_mem, int idx_arr);
int		ft_count_str_elem(char *str);
// normalize.c
int		ft_check_condition_and_normalize(int **origin_arr, int size);
// utils_normalize.c
void	ft_swap(int *arr, int idx);
// stack.c 함수
int		ft_init_n_copy(t_list *stack_a, t_list *stack_b, int argc, int *arr);
int		ft_init_stack(t_list *stack);
int		ft_copy_arr_to_linked_list(t_list *stack, int argc, int *input_arr);
void	ft_insert_list(t_list *stack, int is_at_head, t_node *input_node);
t_node	*ft_delete_list(t_list *stack, int is_at_head);
// utils_stack.c
// commands.c
void	cmd_push(t_list *from_stack, t_list *to_stack, char c);
void	cmd_swap(t_list *stack, char c);
void	cmd_rotate(t_list *stack, char c);
void	cmd_reverse_rotate(t_list *stack, char c);
// simple_sort.c && radix_sort.c
void	simple_sort(t_list *stack_a, t_list *stack_b);
void	radix_sort(t_list *stack_a, t_list *stack_b);
// utils.c
int		ft_free_str_arr(char **str_arr);
int		ft_free_int_arr(int *int_arr);
int		ft_free_stack(t_list *stack);
int		ft_print_error(void);

#endif