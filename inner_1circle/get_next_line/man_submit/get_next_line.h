/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:15:31 by minjeeki          #+#    #+#             */
/*   Updated: 2024/03/27 12:54:05 by minjeeki         ###   ########seoul.kr  */
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

// get_next_line.c의 사용자 정의 함수 프로토타입 명시
char	*get_next_line(int fd);
char	*put_data_in_s_buffer(int fd, char *s_buffer);
char	*read_from_s_buffer(char *s_buffer);
char	*clean_s_buffer_for_next_line(char *s_buffer);
// get_next_line_utils.c의 사용자 정의 함수 프로토타입 명시
// ft_strlen과 ft_strlcat은 utils 파일 내부에서만 사용하기에 명시 안함
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);

#endif