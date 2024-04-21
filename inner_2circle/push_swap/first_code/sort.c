/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:19:29 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/21 22:16:35 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_list *stack, t_node *low, t_node *high)
{
	t_node	*pivot;

	if (high != NULL && low != high && low != high -> right)
	{
		pivot = partition(stack, low, high);
		quick_sort(stack, pivot -> right, high);
		quick_sort(stack, low, pivot -> left);
	}
}

t_node	*partition(t_list *stack, t_node *low, t_node *high)
{
	
}