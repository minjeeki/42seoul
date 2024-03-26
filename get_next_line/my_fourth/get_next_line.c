/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:20:58 by minjeeki          #+#    #+#             */
/*   Updated: 2024/03/26 16:10:28 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// get_next_line 함수 내부에 사용되는 부가적 함수 프로토 타입
char	*put_data_in_s_buffer(int fd, char *s_buffer);
char	*read_from_s_buffer(char *s_buffer);
char	*clean_s_buffer_for_next_line(char *s_buffer);

// get_next_line 함수
char	*get_next_line(int fd)
{
	static char	*s_buffer;
	char		*res_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	s_buffer = put_data_in_s_buffer(fd, s_buffer);
	if (!s_buffer)
		return (0);
	res_line = read_from_s_buffer(s_buffer);
	if (res_line)
		s_buffer = clean_s_buffer_for_next_line(s_buffer);
	return (res_line);
}

char	*put_data_in_s_buffer(int fd, char *s_buffer)
{
	char	*tmp_buffer;
	int		bytes_read;

	tmp_buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp_buffer)
		return (0);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(tmp_buffer, '\n'))
	{
		bytes_read = read(fd, tmp_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(tmp_buffer);
			free(s_buffer);
			return (0);
		}
		tmp_buffer[bytes_read] = 0;
		s_buffer = ft_strjoin(s_buffer, tmp_buffer);
		if (!s_buffer)
			break ;
	}
	free(tmp_buffer);
	return (s_buffer);
}

char	*read_from_s_buffer(char *s_buffer)
{
	char	*line;
	size_t	len_line;
	char	*ptr_newline;
	size_t	idx;

	len_line = 0;
	if (!s_buffer[0])
		return (0);
	ptr_newline = ft_strchr(s_buffer, '\n');
	if (ptr_newline == 0)
		len_line = ft_strlen(s_buffer);
	else
		len_line = (ptr_newline - s_buffer) + 1;
	line = (char *)ft_calloc(len_line + 1, sizeof(char));
	if (!line)
		return (NULL);
	idx = 0;
	while (idx < len_line)
	{
		line[idx] = s_buffer[idx];
		idx++;
	}
	return (line);
}

char	*clean_s_buffer_for_next_line(char *s_buffer)
{
	size_t	i;
	size_t	j;
	char	*leftover;

	i = 0;
	while (s_buffer[i] && s_buffer[i] != '\n')
		i++;
	if (!s_buffer[i])
	{
		free(s_buffer);
		return (0);
	}
	leftover = ft_calloc(ft_strlen(s_buffer) - i + 1, sizeof(char));
	if (!leftover)
		return (NULL);
	i++;
	j = 0;
	while (s_buffer[i])
		leftover[j++] = s_buffer[i++];
	leftover[j] = '\0';
	free(s_buffer);
	return (leftover);
}
