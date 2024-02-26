/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:03:14 by minjeeki          #+#    #+#             */
/*   Updated: 2024/02/26 18:10:48 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

// 허용 가능한 함수 : read함수, malloc 함수, free 함

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif
# define NULL 0

char	*get_next_line(int fd);

#endif

