/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:58:28 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/22 21:58:46 by minjeeki         ###   ########seoul.kr  */
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
// 디버깅을 위해 사용했던 함수와 헤더 파일 (제출 시 삭제 필요)
# include <stdio.h>

// 노드와 연결 리스트 정의
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

// before_sort.c 함수
int		ft_check_validate_n_normalize(int argc, char *argv[], int *origin_arr);
int		ft_count_max_size(int max_n);
char	*ft_convert_binary(int size_str, t_node *new_node);
// data_structure.c 함수
int		ft_init_n_copy(t_list *stack_a, t_list *stack_b, int argc, int *arr);
void	ft_insert_list(t_list *stack, int is_at_head, t_node *input_node);
t_node	*ft_delete_list(t_list *stack, int is_at_head);
// stack_commands.c 함수
void	cmd_push(t_list *from_stack, t_list *to_stack, char c);
void	cmd_swap(t_list *stack, char c);
void	cmd_rotate(t_list *stack, char c);
void	cmd_reverse_rotate(t_list *stack, char c);
// sort.c
void	sort_radix(t_list *stack_a, t_list *stack_b, int argc);
// sort_util.c
int		ft_is_sorted(t_list *stack);
// utils.c 함수
int		ft_free_stack(t_list *stack);
int		ft_free_arr(int *arr);
int		ft_print_error(void);
void	ft_swap(int *arr, int idx);
// 디버깅을 위해 사용했던 함수와 헤더 파일 (제출 시 삭제 필요)
void	ft_print_arr(int argc, int *input_arr);
void	ft_print_stack(t_list *stack);
void	check_leak(void);

#endif