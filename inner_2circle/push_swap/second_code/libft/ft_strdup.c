/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:27:49 by minjeeki          #+#    #+#             */
/*   Updated: 2023/10/20 04:32:23 by minjeeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len_s;
	char	*mal_s;
	size_t	idx;

	len_s = ft_strlen(s1);
	mal_s = (char *) malloc (len_s + 1);
	if (!mal_s)
		return (0);
	idx = 0;
	while (s1[idx])
	{
		mal_s[idx] = s1[idx];
		idx++;
	}
	mal_s[idx] = 0;
	return (mal_s);
}
