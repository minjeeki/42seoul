/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:34:35 by minjeeki          #+#    #+#             */
/*   Updated: 2023/10/28 05:22:36 by minjeeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	if (needle[i] == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[cnt])
		{
			while (i + cnt < len && haystack[i + cnt] == needle[cnt] \
					&& haystack[i + cnt] && needle[cnt])
				cnt++;
			if (cnt == ft_strlen(needle))
				return ((char *)haystack + i);
			else
				cnt = 0;
		}
		i++;
	}
	return (0);
}
