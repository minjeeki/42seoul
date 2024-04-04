/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:30:24 by minjeeki          #+#    #+#             */
/*   Updated: 2024/03/26 10:54:16 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// malloc, free, read 함수 사용을 위한 표준 라이브러리 include
# include <stdlib.h>
# include <unistd.h>
// EOF 매크로 사용을 위한 표준 라이브러리 include
# include <stddef.h>

// 컴파일러 옵션으로 값의 변화를 줄 BUFFER_SIZE 매크로 설정
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// 정적 변수 info_fd의 연결 리스트 선언
typedef struct	info_fd
{
	int				num_fd;
	char			*line_buffer;
	int				idx_newline_char;
	struct info_fd	*next;
} t_info_fd;
// get_next_line.c의 사용자 정의 함수 프로토타입 명시

// get_next_line_utils.c의 사용자 정의 함수 프로토타입 명시

#endif