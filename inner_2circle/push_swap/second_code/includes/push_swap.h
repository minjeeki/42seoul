/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:17:03 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/28 21:15:10 by minjeeki         ###   ########seoul.kr  */
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
/* 최종 제출 시 주석 처리해야 하는 부분 */
# include <stdio.h>
// self_debug.c
void	ft_print_int_arr(int *origin_arr, int size_arr);
void	ft_print_str_arr(char	**origin_arr);
// parsing.c
int		ft_parsing(int argc, char *argv[], int **origin_arr);
// utils_parsing.c
int		ft_size_str(char *str);
int		ft_safe_atoi(char *str, int *arr_mem, int idx_arr);
int		ft_count_str_elem(char *str);
// sort_.c
// utils.c
int		ft_free_str_arr(char **str_arr);
int		ft_print_error(void);

#endif