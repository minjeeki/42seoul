/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:41:13 by minjeeki          #+#    #+#             */
/*   Updated: 2023/10/28 18:09:59 by minjeeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	is_set(char c, const char *set)
{
	int	idx;

	idx = 0;
	while (set[idx])
	{
		if (set[idx] == c)
			return (1);
		idx++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t		idx_s;
	size_t		idx_e;
	size_t		len_res;
	char		*res;

	idx_s = 0;
	if (!ft_strlen(s1))
	{
		res = (char *)ft_calloc(1, 1);
		return (res);
	}
	idx_e = ft_strlen(s1) - 1;
	while (is_set(s1[idx_s], set) && s1[idx_s])
		idx_s++;
	while (is_set(s1[idx_e], set) && idx_e > idx_s)
		idx_e--;
	len_res = idx_e - idx_s + 1;
	res = ft_substr(s1, idx_s, len_res);
	return (res);
}
