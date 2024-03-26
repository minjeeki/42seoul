/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:25:35 by minjeeki          #+#    #+#             */
/*   Updated: 2024/03/26 16:18:55 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	if (!s)
		return (0);
	idx = 0;
	while (s[idx] != 0)
		idx++;
	return (idx);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (*str == c)
		return ((char *)str);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	total_size;
	size_t	i;

	total_size = count * size;
	ptr = (char *)malloc(total_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = (char *)ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!result)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	i = 0;
	while (i < len_s1)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
	{
		result[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (result);
}
