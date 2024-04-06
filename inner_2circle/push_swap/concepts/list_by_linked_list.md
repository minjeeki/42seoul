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

### 노드 생성 (= 동적 할당을 통한 노드 생성)

- 노드를 동적할당했다고 노드가 연결 리스트에 연결되어 있다는 의미는 아니다.

- 첫번째 노드 생성 : 동적 할당 -> 필드 값 부여 -> head 포인터에 해당 노드의 포인터값 할당
	
	```C
	ListNode* linkNode(ListNode* previous, int newData)
	{
		ListNode*	newNode;
		
		newNode = (ListNode*)malloc(sizeof(ListNode));
		if (newNode == NULL)
			error("malloc failed");
		newNode -> data = newData;
		newNode -> next = NULL;

		previous = newNode;
		return (previous);
	}
	```