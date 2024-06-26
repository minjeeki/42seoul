/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:10:59 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/27 22:14:23 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

enum {
	INTG_MAX = 2147483647,
	INTG_MIN = -2147483648
};

typedef struct s_node
{
	int				elem;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*top;
	int		max[3];
	int		min;
	int		cnt;
}				t_stack;

typedef struct s_op_cnt
{
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	char	min_type;
	int		min_cnt;
	t_node	*node;
}				t_op_cnt;

/*
*** push_swap.c ***
*/
void	push_swap(t_stack *a, t_stack *b);

/*
*** checker.c ***
*/
void	checker(t_stack *a, t_stack *b);

/*
*** choose_best_elem.c ***
*/
void	count_op_b(t_node *node, t_stack *b, t_op_cnt *op_cnt);
void	count_op_a(t_node *node, t_stack *a, t_op_cnt *op_cnt);
void	choose_min_op(t_node *node, t_stack *a, t_stack *b, t_op_cnt *op_cnt);
void	set_a_max(t_stack *a);
void	choose_best_elem(t_stack *a, t_stack *b, t_op_cnt *op_cnt);

/*
*** pb_and_set_b.c ***
*/
int		loop_do_op(t_stack *a, t_stack *b, int n, const char *op);
void	pb_best_elem_sub(t_stack *a, t_stack *b, t_op_cnt *op_cnt);
void	pb_best_elem(t_stack *a, t_stack *b, t_op_cnt *op_cnt);
void	set_b_max_on_top(t_stack *a, t_stack *b);

/*
*** simple_sort.c ***
*/
void	sort_3(t_stack *a, t_stack *b);
void	sort_2(t_stack *a, t_stack *b);
void	simple_sort(t_stack *a, t_stack *b);

/*
*** get_values.c ***
*/
void	handle_error(void);
void	add_last(t_stack *stack, int elem);
char	*get_values_sub(t_stack *a, const char *str, int sign);
char	*get_values(t_stack *a, const char *str);

/*
*** do_op.c ***
*/
int		is_sorted(t_stack *a);
void	print_op(const char *op, int print);
void	do_op_sub_2(t_stack *a, t_stack *b, const char *op, int print);
void	do_op_sub_1(t_stack *a, t_stack *b, const char *op, int print);
void	do_op(t_stack *a, t_stack *b, const char *op, int print);

/*
*** op.c ***
*/
void	push(t_stack *a, t_stack *b);
void	swap(t_stack *a);
void	rotate(t_stack *a);
void	reverse_rotate(t_stack *a);

/*
*** stack utils.c ***
*/
void	init_stack(t_stack *stack);
t_node	*getnode(t_node *next, int elem);
void	free_stack(t_stack *stack);
void	add_node(t_stack *stack, int elem);
int		remove_node(t_stack *stack);

#endif