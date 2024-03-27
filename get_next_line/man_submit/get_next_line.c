/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:20:58 by minjeeki          #+#    #+#             */
/*   Updated: 2024/03/27 21:33:15 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// get_next_line 함수 내부에 사용되는 부가적 함수 프로토 타입
char	*put_data_in_s_buffer(int fd, char *s_buffer);
char	*read_from_s_buffer(char *s_buffer);
char	*clean_s_buffer_for_next_line(char *s_buffer);
char	*free_and_return(char *ptr);

// get_next_line 함수
char	*get_next_line(int fd)
{
	static char	*s_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	s_buffer = put_data_in_s_buffer(fd, s_buffer);
	if (!s_buffer)
		return (0);
	line = read_from_s_buffer(s_buffer);
	if (!line)
	{
		s_buffer = free_and_return(s_buffer);
		return (0);
	}
	if (ft_strchr(s_buffer, '\n') == 0)
		s_buffer = free_and_return(s_buffer);
	else
	{
		s_buffer = clean_s_buffer_for_next_line(s_buffer);
		if (!s_buffer)
			return (free_and_return(line));
	}
	return (line);
}

char	*put_data_in_s_buffer(int fd, char *s_buffer)
{
	char	*tmp_buffer;
	int		bytes_read;

	tmp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp_buffer)
	{
		s_buffer = free_and_return(s_buffer);
		return (0);
	}
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(s_buffer, '\n'))
	{
		bytes_read = read(fd, tmp_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(tmp_buffer);
			return (free_and_return(s_buffer));
		}
		tmp_buffer[bytes_read] = '\0';
		s_buffer = ft_strjoin(s_buffer, tmp_buffer);
		if (!s_buffer)
			break ;
	}
	free(tmp_buffer);
	return (s_buffer);
}

char	*read_from_s_buffer(char *s_buffer)
{
	size_t	len_line;
	char	*line;
	size_t	idx;

	if (!s_buffer[0])
		return (0);
	len_line = 0;
	while (s_buffer[len_line] && s_buffer[len_line] != '\n')
		len_line++;
	if (s_buffer[len_line] == '\n')
		len_line++;
	line = ft_calloc(len_line + 1, sizeof(char));
	if (!line)
		return (NULL);
	idx = 0;
	while (s_buffer[idx] != '\n' && s_buffer[idx] != 0)
	{
		line[idx] = s_buffer[idx];
		idx++;
	}
	if (s_buffer[idx] == '\n')
		line[idx] = '\n';
	return (line);
}

char	*clean_s_buffer_for_next_line(char *s_buffer)
{
	size_t	idx_newline;
	size_t	idx;
	char	*new_s_buffer;
	size_t	len_new_buffer;

	idx_newline = 0;
	while (s_buffer[idx_newline] != '\n')
		idx_newline++;
	len_new_buffer = ft_strlen(s_buffer) - idx_newline;
	new_s_buffer = ft_calloc(len_new_buffer + 1, sizeof(char));
	if (!new_s_buffer)
	{
		free(s_buffer);
		return (NULL);
	}
	idx = 0;
	while (s_buffer[idx_newline + 1 + idx] != 0)
	{
		new_s_buffer[idx] = s_buffer[idx_newline + 1 + idx];
		idx++;
	}
	free(s_buffer);
	return (new_s_buffer);
}

char	*free_and_return(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return (ptr);
}
