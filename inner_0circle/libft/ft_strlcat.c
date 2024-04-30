/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:34:19 by minjeeki          #+#    #+#             */
/*   Updated: 2023/10/20 04:16:03 by minjeeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx_d;
	size_t	idx_s;
	size_t	len_d;
	size_t	len_s;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	idx_d = len_d;
	idx_s = 0;
	while (src[idx_s] != 0 && (idx_s + len_d + 1) < dstsize)
	{
		dst[idx_d] = src[idx_s];
		idx_d++;
		idx_s++;
	}
	dst[idx_d] = 0;
	if (len_d < dstsize)
		return (len_d + len_s);
	else
		return (len_s + dstsize);
}
