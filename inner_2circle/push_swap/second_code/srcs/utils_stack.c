/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 03:36:13 by minjeeki          #+#    #+#             */
/*   Updated: 2024/04/30 02:08:32 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_get_binary_str(int size_arr, t_node *new_node)
{
	char	*binary_str;
	int		max_bits;
	int		idx;
	int		digit_num;

	max_bits = get_max_bits(size_arr - 1);
	binary_str = (char *)ft_calloc((max_bits + 1), sizeof(char));
	if (binary_str == NULL)
		return (NULL);
	binary_str[max_bits] = '\0';
	idx = 0;
	digit_num = new_node -> data;
	while (idx < max_bits)
		binary_str[idx++] = '0';
	idx--;
	while (idx >= 0 && digit_num >= 1)
	{
		binary_str[idx--] = '0' + (digit_num % 2);
		digit_num /= 2;
	}
	return (binary_str);
}

int	ft_is_ascend(t_list *stack)
{
	int		idx;
	t_node	*cur;

	if (stack -> size < 2)
		return (1);
	cur = stack -> head -> right -> right;
	while (cur -> right != NULL)
	{
		if (cur -> data < cur -> left -> data)
			return (0);
		cur = cur -> right;
	}
	return (1);
}
