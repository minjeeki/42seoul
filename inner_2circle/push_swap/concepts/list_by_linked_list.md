# 단순 연결 리스트 구현하기

## 노드 정의

- 노드는 자기 참조 구조체를 이용해 정의한다.

	- 자기 참조 구조체 : 자기 자신을 참조하는 포인터를 포함하는 구조체

	- 자신과 동일한 형태의 구조체를 가리키는 포인터를 의미함 (포인터가 가리키는 데이터가 자기 자신과 동일한 타입의 다른 인스턴스를 가질 수 있게 하는 것)

- 구조체 내부에는 data 필드 (데이터 저장), link 필드 (포인터 저장)가 존재하며, data 필드는 element 타입의 데이터를 저장한다.

| 노드를 정의했다고 노드가 생성된 것은 아니다. 노드의 정의는 노드를 만들기 위한 설계도일 뿐이다.

```C
typedef int element;
typedef struct {
	element data;
	struct ListNode *next;
} ListNode;
```

## 연결 리스트 인스턴스 생성 (공백 리스트 생성 -> 노드 생성 -> 노드 연결)

### 공백 리스트 생성 (= 헤드 포인트 정의하기)

: 노드를 가리키는 포인터 head를 정의할 경우 하나의 단순 연결 리스트가 만들어졌다고 볼 수 있다.

=> 단순 연결 리스트는 원칙적으로 헤드 포인터만 있으면 된다.

```C
ListNode *head;
head = NULL;
```

- 특정 연결 리스트의 공백 여부를 확인하기 위해서는 head 포인터가 NULL 값을 갖고 있는지 검사하면 된다.

### 노드 생성(= 동적 할당을 통한 노드 생성) 및 헤드 포인터 연결 

- 노드를 동적할당했다고 노드가 연결 리스트에 연결되어 있다는 의미는 아니다.

- 첫번째 노드 생성 : 동적 할당 -> 필드 값 부여 -> head 포인터에 해당 노드의 포인터값 할당
	
	```C
	ListNode* link_first_node(ListNode* head, int newData)
	{
		ListNode*	newNode;
		
		// 새로운 노드 동적 할당 및 값 부여 (현재 가장 끝에 위치해있기에 next는 NULL 값)
		newNode = (ListNode*)malloc(sizeof(ListNode));
		if (newNode == NULL)
			error("malloc failed");
		newNode -> data = newData;
		newNode -> next = NULL;
		// head 포인터에 연결 (현재 함수 자체가 빈 연결 리스트에 노드를 붙이는 것이기에 예외 처리를 추가함)
		if (head != NULL)
			error("linked list is not empty.");
		// head 원본의 주솟값을 변경해야 하는 것이기에 복사본이 아닌 구조체 포인터가 들어와야 함
		head = newNode;
		return (head);
	}
	```

- 이후 노드들은 head 포인터에서 지칭하는 노드의 next 값이 NULL일 때까지 재설정한 후

	NULL을 만나면 새로운 노드의 포인터를 해당 next값에 재할당하면 됨

	```C
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
	```

## 연결 리스트 연산 구현

- 우리가 만든 연결 리스트는 순차적으로 들어온 값을 넣기도 하지만, 특정 위치의 값을 추가 or 삭제하기도 한다

	=> 리스트가 커질 경우 추상 데이터 타입에 정의된 전용 함수들을 통해 노드를 추가하는 것이 편리하다.

- 작성할 함수

	- insert_first() : 리스트의 시작 부분에 항목을 삽입하는 함수

	- insert() : 리스트의 중간 부분에 항목을 삽입하는 함수

	- delete_first() : 리스트의 첫번째 항목을 삭제하는 함수

	- delete() : 리스트의 중간 항목을 삭제하는 함수

	- print_list() : 리스트를 방문해 모든 항목을 출력하는 함수

### insert_first() : 리스트 시작 부분 항목 삽입