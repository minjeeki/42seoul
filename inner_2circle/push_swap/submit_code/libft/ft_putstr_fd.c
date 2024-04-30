/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:42:33 by minjeeki          #+#    #+#             */
/*   Updated: 2023/10/28 06:00:01 by minjeeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	idx;
	size_t	len_s;

	idx = 0;
	len_s = ft_strlen(s);
	while (idx < len_s)
	{
		write(fd, &s[idx], 1);
		idx++;
	}
}
