/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeeki <minjeeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:53:06 by minjeeki          #+#    #+#             */
/*   Updated: 2024/03/24 09:51:17 by minjeeki         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* 요약
궁극적으로 만들어야 하는 것 : 호출할 때마다 한번에 한줄 씩 파일 디스크립터가 가리키는 텍스트 파일을 읽는 함수
반환값 : (정상) Read Line - 읽은 한줄의 문자열 (에러 또는 읽을 것 없는 상태) NULL (헤더에 미리 선언 완료)

인터넷 상 코드 동작
1. 입력값 예외 처리 : fd와 BUFFER_SIZE에 대한 예외 처리
2. 한 줄 읽기 : 읽을 시작점, 개행 문자 또는 파일의 끝에 도달하기까지 길이, 계산 후 buffer에 담기
3. 줄 반환 하기 : buffer에 담은 내용을 반환값에 넣기
4. 다음에 읽을 줄 대기 시키기

나의 코드 동작
1. 입력값 예외 처리
2. 버퍼 크기만큼 
3. read() 결과가 파일 끝, 개행 문자일 경우 현재 담은 버퍼까지만 반환 문자열에 붙임
4. read()를 하다가 buffer가 가득 차게 될 경우 버퍼를 반환 문자열에 붙이고 
*/
char	*get_next_line(int fd)
{
	// 변수 설정
	static char	*left_str;	// 정적 변수 : 파일을 읽어올 위치 (하나를 읽을 때마다 값이 더해져야 함)
	char		*one_line;	// 반환할 한줄의 문자열
	char		*buf;
	int			idx_buf;
	int			flag_put_one_line_before;
	int			len_one_line;
	
	// 예외 처리
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);		// 컴파일 옵션으로 받은 버퍼 사이즈가 자연수가 아닌 경우 & 입력 받은 fd값이 음수일 경우
	// 버퍼 배열 만들기 & 정적 변수 초기화 (어차피 초기화는 처음 실행된 한번만 수행할 것임)
	buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	idx_buf = 0;
	while (idx_buf < BUFFER_SIZE)
	{
		buf[idx_buf] = 0;
		idx_buf++;
	}
	idx_buf = 0;
	left_str = 0;
	flag_put_one_line_before = 0;
	len_one_line = 0;
	// 한 글자씩 받아 처리
	while (1)
	{
		if (read(fd, buf[idx_buf], 1) < 0)
		{					// 조건문 확인하며 한글자씩 읽음
			if (flag_put_one_line_before == 0)
			{
				one_line = (char *)malloc(idx_buf + 1);
				if (!one_line)
					return (NULL);
				one_line[0] = '\0';
			}
			ft_strncat(one_line, buf, idx_buf);
			free(left_str);	// 정적 변수에 대해서 더이상 읽을 것이 없기 떄문에 할당 해제 필요
			break ;			// 파일 끝을 읽었을 경우 이전까지 버퍼 담긴 내용 옮기고 break
		}
		else
		{					// 파일 끝을 읽은 것이 아니기에 다음에 문자가 있음
			left_str++;		// 다음에 읽을 것을 준비함 (설령 개행을 만나 끝나더라도 다음 위치를 가리켜야 하기 때문)
			len_one_line++;
			if (buf[idx_buf] == '\n')
			{
				if (flag_put_one_line_before == 0)
				{
					one_line = (char *)malloc(idx_buf + 1);
					if (!one_line)
						return (NULL);
					one_line[0] = '\0';
				}
				ft_strncat(one_line, buf, idx_buf + 1);
				break ;		// 개행 문자를 읽었을 경우 개행문자까지 포함해 one_line을 만든 뒤 더 이상 읽지 않음 (반복문 종료)
			}
			if (idx_buf == BUFFER_SIZE - 1)
			{
				if (flag_put_one_line_before == 0)
				{
					one_line = (char *)malloc(idx_buf + 1);
					if (!one_line)
						return (NULL);
					one_line[0] = '\0';
				}
				ft_strncat(one_line, buf, BUFFER_SIZE);
				idx_buf = 0;
			}				// 버퍼 사이즈만큼 모두 읽었을 경우 버퍼 내용문을 one_line에 담고 idx를 0으로 맞춰 다시 채운다.
			else
				idx_buf++;	// 버퍼를 다 채우지도, 개행 문자를 만나지도 않았기에 다음 문자를 읽을 준비를 함
		}
	}
	// 완성된 반환값을 문자열 형식에 맞추기 위해 마지막에 널 문자 추가 & buffer 할당 해제
	one_line[len_one_line] = '\0';
	free(buf);
	// 최종 결과 반환
	return (one_line);
}

