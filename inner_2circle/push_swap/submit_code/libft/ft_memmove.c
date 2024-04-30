/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 06:40:44 by minjeeki          #+#    #+#             */
/*   Updated: 2023/10/28 16:07:37 by minjeeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		idx;

	if ((!dst && !src) || len == 0)
		return (dst);
	if ((char *)dst > (char *)src)
	{
		idx = len - 1;
		while (idx >= 0)
		{
			((char *)dst)[idx] = ((char *)src)[idx];
			idx--;
		}
	}
	else
	{
		idx = 0;
		while (idx < (int)len)
		{
			((char *)dst)[idx] = ((char *)src)[idx];
			idx++;
		}
	}
	return (dst);
}
