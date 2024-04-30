/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:48:29 by minjeeki          #+#    #+#             */
/*   Updated: 2023/10/31 17:25:19 by minjeeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	size;
	size_t	idx;

	if (start >= ft_strlen(s))
		size = 0;
	else
	{
		if ((ft_strlen(s) - start) > len)
			size = len;
		else
			size = (ft_strlen(s) - start);
	}
	res = (char *) malloc (size + 1);
	if (!res)
		return (0);
	res[size] = 0;
	idx = 0;
	while (idx < size)
	{
		res[idx] = s[start + idx];
		idx++;
	}
	return (res);
}
