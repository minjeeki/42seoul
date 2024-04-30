/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:47:46 by minjeeki          #+#    #+#             */
/*   Updated: 2023/10/28 06:29:17 by minjeeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			idx;
	unsigned char	*copy_s;

	idx = 0;
	copy_s = (unsigned char *)s;
	while (idx < n)
	{
		if (copy_s[idx] == (unsigned char)c)
			return (copy_s + idx);
		idx++;
	}
	return (0);
}
