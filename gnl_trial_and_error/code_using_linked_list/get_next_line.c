/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:32:15 by minjeeki          #+#    #+#             */
/*   Updated: 2024/03/26 16:07:10 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// get_next_line 함수 내부에서 사용되는 함수 프로토 타입

// get_next_line 함수
char	*get_next_line(int fd)
{
	// 정적 변수로 head 구조체 포인터 설정
	static t_info_fd *head;

	// head 구조체에 대한 값 할당

	// while문을 돌면서 num_fd 값의 일치 유무 및 존재 유무 확인 (없을 경우 새로 노드 정의)

}