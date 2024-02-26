/*
## 로직 정리하기 (1차)
0. 처음에 주어진 값들에 대한 예외 처리 필요 (버퍼 사이즈 0 이하, fd 값 음수)
1. 파일로부터 문자열을 읽어올 버퍼 동적할당 & 할당 실패 시 널가드
2. 읽어야 하는 길이 정수값 확인 후 oneline_len = (개행 위치 - 현재 위치) 구하기
3. 한줄의 문자열을 모두 담아 반환값으로 보낼 res 문자열 동적 할당으로 선언
	* 문자열 내부에는 개행 문자와 널값 모두 들어가야 한다는 것 반드시 기억할 것
4. 반복문 돌릴 횟수 rotate_cnt = (버퍼 사이즈) / (oneline_len)
4-1. rotate_cnt += ((버퍼 사이즈) % (oneline_len)) > 0 ? 1 : 0
5. rotate_cnt만큼 반복문을 돌면서
5-1. 데이터 값만큼 읽어 버퍼에 담기, 버퍼에 담은 내용을 res에 옮기고 버퍼 값 비우기
	* 개행 문자 만날 경우 개행 문자 담고, 널 문자 담아서 종료
	* 파일 끝 (널문자)일 경우 널 문자 전까지만 읽고 널 문자 담아서 종료
7. res 반환
*/
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char *start_ptr;
	static char	*end_ptr;
	int			oneline_len;
	char		*result;
	int			rotate_cnt;
	
	// 컴파일 옵션으로 받은 BUFFER_SIZE가 자연수가 아닐 경우 & fd 입력값이 음수일 경우 예외 처리 
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// 1. 버퍼 동적 할당 & 널가드
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	// 2. 문장의 끝 주소값 & 한줄의 길이 구하기
	end_ptr = ft_find_line_end(end_ptr, fd);
	oneline_len = (int)(end_ptr - start_ptr);
	// 3. 반환값으로 사용할 문자열 동적 할당 & 널가드
	result = (char *)malloc((oneline_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	// 4. 반복문 돌릴 횟수 계산하기
	rotate_cnt = BUFFER_SIZE / oneline_len;
	rotate_cnt += (BUFFER_SIZE % oneline_len) > 0 ? 1 : 0;
	// 5. 반복문 돌면서 작업 진행
}
/*
## 해당 로직의 문제점
* 파일 디스크립터 내에서 문자를 읽기 위해서는 시스템 호출 함수 read()를 사용해야 하는데
read() 함수를 활용할 생각과 정적 변수 end_ptr을 어떻게 받을지에 대한 생각이 미흡했다.
* 변수 개수 제한과 함수 줄 제한이 있는데 이부분을 효율적으로 사용할 방식이 필요할 것 같다.
*/