/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opttimization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:47:59 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/21 15:52:16 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_list *stack, char c)
{
	if (ft_is_sorted(stack))
		return ;
	else
		ft_swap(stack, c);
}

void	ft_sort_three(t_list *stack, char c)
{
	t_node	*first_node;
	t_node	*second_node;
	int		gap_first_second;

	first_node = stack -> head -> right;
	second_node = first_node -> right;
	gap_first_second = (first_node -> data) - (second_node -> data);
	if (ft_is_sorted(stack))
		return ;
	else if (gap_first_second == -2)
	{
		cmd_reverse_rotate(stack, c);
		cmd_swap(stack, c);
	}
	else if (gap_first_second == -1)
		cmd_reverse_rotate(stack, c);
	else if (gap_first_second == 2)
		cmd_rotate(stack, c);
	else if (gap_first_second == 1)
	{
		if (second_node -> data > second_node -> right -> data)
			cmd_rotate(stack, c);
		cmd_swap(stack, c);
	}

}