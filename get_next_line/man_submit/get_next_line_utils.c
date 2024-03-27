/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:25:35 by minjeeki          #+#    #+#             */
/*   Updated: 2024/03/27 20:36:42 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	idx;

	if (!s)
	{
		free(s);
		return (0);
	}
	idx = 0;
	while (s[idx] != 0)
		idx++;
	return (idx);
}

char	*ft_strchr(char *s, int c)
{
	size_t	idx;

	if (!s)
	{
		free(s);
		return (NULL);
	}
	if (c == '\0')
		return (s + ft_strlen(s));
	idx = 0;
	while (s[idx] != 0)
	{
		if (s[idx] == c)
			return (s + idx);
		idx++;
	}
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void				*res;
	unsigned char		*ptr;
	size_t				total_size;
	size_t				idx;

	total_size = count * size;
	res = (void *)malloc(total_size);
	if (!res)
		return (NULL);
	ptr = (unsigned char *)res;
	idx = 0;
	while (idx < total_size)
	{
		ptr[idx] = 0;
		idx++;
	}
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	res = ft_calloc((len_s1 + ft_strlen(s2) + 1), sizeof(char));
	if (res != NULL)
	{
		i = 0;
		while (i < len_s1)
		{
			res[i] = s1[i];
			i++;
		}
		i = 0;
		while (i < ft_strlen(s2))
		{
			res[len_s1 + i] = s2[i];
			i++;
		}
	}
	free(s1);
	return (res);
}
