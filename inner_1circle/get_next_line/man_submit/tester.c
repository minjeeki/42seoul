// 컴파일 명령어 : cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line.h get_next_line_utils.c tester.c
// BUFFER_SIZE 해당 값은 알아서 원하는 것으로 변경!

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int		fd;
	char	*line;
	int		repeat_gnl_func;
	int		idx;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open the file.\n");
		return (1);
	}
	printf("GNL 함수를 동작할 횟수를 구하세요 : ");
	scanf("%d", &repeat_gnl_func);
	idx = 0;
	while (idx < repeat_gnl_func)
	{
		line = get_next_line(fd);
		printf("%d번째 실행 결과 : %s", idx, line);
		idx++;
	}
	close(fd);
	return (0);
}