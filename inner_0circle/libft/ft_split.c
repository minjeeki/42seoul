/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:12:24 by minjeeki          #+#    #+#             */
/*   Updated: 2023/10/31 20:54:46 by minjeeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	**free_all(char **res, int cur)
{
	while (cur >= 0)
	{
		free(res[cur]);
		cur--;
	}
	free(res);
	return (0);
}

int	ft_cnt_words(const char *s, char c)
{
	int	is_c;
	int	idx;
	int	cnt;

	is_c = 1;
	idx = 0;
	cnt = 0;
	while (s[idx])
	{
		if (s[idx] == c && is_c == 0)
			is_c = 1;
		else if (s[idx] != c && is_c == 1)
		{
			is_c = 0;
			cnt++;
		}
		idx++;
	}
	return (cnt);
}

char	*ft_fill_char(char *to_word, const char *s, int end, int len_word)
{
	int	idx;
	int	start;

	idx = 0;
	start = end - len_word;
	while (idx < len_word)
	{
		to_word[idx] = s[start + idx];
		idx++;
	}
	to_word[idx] = 0;
	return (to_word);
}

char	**ft_split_words(const char *s, char c, char **res, int num_words)
{
	int	idx;
	int	idx_word;
	int	len_word;

	idx = 0;
	idx_word = 0;
	while (idx_word < num_words)
	{
		len_word = 0;
		while (s[idx] && s[idx] == c)
			idx++;
		while (s[idx] && s[idx] != c)
		{
			idx++;
			len_word++;
		}
		if (len_word != 0)
		res[idx_word] = (char *)malloc(sizeof(char) * (len_word + 1));
		if (!res[idx_word])
			return (free_all(res, idx_word));
		ft_fill_char(res[idx_word], s, idx, len_word);
		idx_word++;
	}
	res[idx_word] = 0;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	num_words;

	if (!s)
		return (0);
	num_words = ft_cnt_words(s, c);
	res = (char **)malloc (sizeof(char *) * (num_words + 1));
	if (!res)
		return (0);
	res = ft_split_words(s, c, res, num_words);
	return (res);
}
