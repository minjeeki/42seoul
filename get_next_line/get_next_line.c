#include "get_next_line.h"

// 호출할 때마다 한번에 한줄 씩 파일 디스크립터가 가리키는 텍스트 파일을 읽는 함수
// 반환값 : (정상) Read Line - 읽은 한줄의 문자열 (에러 또는 읽을 것 없는 상태) NULL (헤더에 미리 선언 완료)
char	*get_next_line(int fd)
{
	static char	*left_str;
	char		*one_line;
	
	// 컴파일 옵션으로 받은 BUFFER_SIZE가 자연수가 아닐 경우 & fd 입력값이 음수일 경우 예외 처리 
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// 한줄을 읽고, 
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	one_line = ft_get_line(left_str);
	left_str = ft_set_new_left_str(left_str);
	return (one_line);
}

