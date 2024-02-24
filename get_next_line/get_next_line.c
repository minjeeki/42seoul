#include "get_next_line.h"

// 호출할 때마다 한번에 한줄 씩 파일 디스크립터가 가리키는 텍스트 파일을 읽는 함수
char	*get_next_line(int fd)
{
	// 처리해야 하는 상황 : 바이너리 파일을 읽을 때 (정의되지 않은 동작으로 생각 or 논리적 구현)
	// 반환값 : (정상) Read Line - 읽은 한줄의 문자열 (에러 또는 읽을 것 없는 상태) NULL
}