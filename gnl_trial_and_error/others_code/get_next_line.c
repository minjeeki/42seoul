/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 03:38:07 by minjeeki          #+#    #+#             */
/*   Updated: 2024/03/25 08:24:13 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*leftover;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	leftover = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		leftover[j++] = buffer[i++];
	leftover[j] = '\0';
	free(buffer);
	return (leftover);
}

static char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*ft_read_line(int fd, char *buffer)
{
	char	*read_now;
	int		read_bytes;

	read_now = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_now)
		return (0);
	read_bytes = 1;
	while (read_bytes != 0 && !ft_strchr(buffer, '\n'))
	{
		read_bytes = read(fd, read_now, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(read_now);
			return (0);
		}
		read_now[read_bytes] = '\0';
		buffer = ft_strjoin(buffer, read_now);
	}
	free(read_now);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read_line(fd, buffer);
	if (!buffer)
		return (0);
	line = ft_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}
