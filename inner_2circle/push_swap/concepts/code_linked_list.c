#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct list_node{
	element				data;
	struct list_node*	next;
} t_list_node;

// 에러 발생 시 에러 결과 출력 후 종료
void	ft_error(char *message)
{
	printf("%s\n", message);
	exit(1);
}

// 노드 생성 (할당, 값  부여) & 리스트에 노드 연결
t_list_node*	insert_data(t_list_node* previous, element new_data)
{
	t_list_node*	new_node;
	t_list_node*	cur_node;

	// 노드 생성 (할당, 값 부여)
	new_node = (t_list_node*)malloc(sizeof(t_list_node));
	if (new_node == NULL)
		ft_error("failed malloc");
	new_node -> data = new_data;
	new_node -> next = NULL;
	// 리스트 (헤드 포인터)에 노드 처음 연결할 경우 (원본 포인터 값 변경해야 하기에 포인터로 값 받아야 함)
	if (previous == NULL)
		previous = new_node;
	// 리스트의 노드 순회하며 next가 NULL인 위치에 새로 생성한 노드 포인터 연결
	else
	{
	cur_node = previous;
	while (cur_node -> next != NULL)
		cur_node = (cur_node -> next);
	(cur_node -> next) = new_node;
	}
	return (previous);
}
int	main(int argc, char	*argv[])
{
	t_list_node*	head;
	t_list_node*	cur_node;

	// 리스트 생성 및 커맨드라인 인자 리스트에 담기
	head = NULL;
	for (int i=1; i<argc; i++)
		head = insert_data(head, atoi(argv[i]));
	// 리스트에 담은 데이터값 전부 출력
	cur_node = head;
	while (cur_node -> next != NULL)
	{
		printf("%d -> ", cur_node -> data);
		cur_node = (cur_node -> next);
	}
	printf("%d\n", cur_node -> data);
	return (0);
}