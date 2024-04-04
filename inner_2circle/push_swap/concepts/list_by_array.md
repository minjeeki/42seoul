# 배열을 통한 리스트 구현

## 리스트 정의

```C
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int		size;
} ArrayListType;

void error(char message)
{
	printf("%s\n", message);
	exit (1);
}
```

- 구조체를 이용해 요소를 담을 리스트 배열과 배열에 담긴 요소의 개수를 의미하는 size를 설정

### 리스트 인스턴스 선언

- 정적 할당 및 선언

	```C
	ArrayListType L_instance;
	ArrayListType *L;
	
	L = &L_instance;
	```

- 동적 할당 및 선언

	```C
	ArrayListType *L;

	L = malloc(sizeof(ArrayListType));
	if (L == NULL)
		error("malloc failed");
	// 모든 작업 이후 free(L) 잊지 말자.
	```

- 정적 할당이 아닌 동적 할당으로 할 경우 갖는 이점

	: 여러개의 구조체가 필요한 상황에서 구조체마다 정적 할당할 경우 구조체가 모두 stack 영역에 저장되고 stack 영역을 넘어서 데이터를 저장하는 stackoverflow가 위험이 있을 수 있다. 따라서 동적 할당으로 stack 영역이 아닌 heap 영역에 할당한 후 사용 종료 시 메모리 해제를 해주면서 최적화를 해주는 것이 좋다.

### 리스트 연산

- 리스트 연산 시 넣는 인수는 무조건 '구조체 포인터'여야 한다.

	: 함수 안에서 구조체 내 데이터를 변경해야 하는 상황이 있기 때문에 포인터로 구조체 원본에 접근할 수 있도록 해야 한다.

	(포인터가 아닌 구조체를 받을 경우 함수는 구조체의 원본이 아닌 복사본을 전달받는 것이기에 원본은 수정할 수 없다.)

- 구조체 포인터 멤버 접근 연산자 (=화살표 연산자)

	- 형태 : `구조체_포인터 -> 멤버`

	- 역할 : 구조체 포인터로 접근한 구조체의 멤버의 값을 불러와 할당, 대소 비교에 사용할 수 있음

	- 괄호와 역참조 연산자를 이용한 `(*구조체_포인터).멤버` 와 동일한 기능을 함

#### 리스트 초기화

```C
void init(ArrayListType *L)
	L -> size = 0;
```

#### 리스트가 비어있는지 확인 (비어있을 경우 1, 하나라도 차있을 경우 0)

```C
int is_empty (ArrayListType *L)
	return (L -> size == 0);
```

#### 리스트가 가득 차있는지 확인 (가득 차있을 경우 1, 비어있거나 일부만 차있을 경우 0)

```C
int is_full (ArrayListType *L)
	return (L -> size == MAX_LIST_SIZE);
```

#### 탐색 연산 (특정 위치의 요소 값 반환)

```C
element get_entry(ArrayListType *L, int pos)
{
	if (pos < 0 || pos >= MAX_LIST_SIZE)
		error("Invalid pos");
	return (L -> array[pos]);
}
```

#### 리스트 전체 출력

```C
void print_list(ArrayListType *L)
{
	for (int idx=0; idx<(L->size); idx++)
		printf("%d -> ", L -> array[idx]);
	printf("\n");
}
```

#### 리스트 추가 연산

- 의사 코드

	1. 예외 처리 : size가 MAX_LIST_SIZE일 경우 / pos 값이 유효하지 않을 때

	2. [pos + 1] 위치에 [pos] 값 할당 <- [size - 1]에 [size - 2] 값 할당부터 시작

	3. [pos]에 값 추가 -> size++

```C
void insert_pos(ArrayListType *L, int pos, element item)
{
	if (L->size == MAX_LIST_SIZE)
		error("array overflow");
	else if (pos < 0 || pos > L->size)
		error("invalid pos");
	else
	{
		for (int idx = (L->size - 2); idx >= pos; idx--)
			L->array[idx+1] = L->array[idx];
		L->array[pos] = item;
		L->size++;
	}
}
```

#### 리스트 삭제 연산

- 의사 코드

	1. 예외 처리 : pos 값이 유효하지 않을 경우 (array overflow는 고려 안함)

	2. [pos] 값에 [pos+1] 값 대입 -> [size-2] 값에 [size-1] 값 대입

	3. size--;

```C
element delete_pos(ArrayListType *L, int pos)
{
	elemenet item;
	
	if (pos < 0 || pos > (L->size - 1))
		error("invalid pos");
	else
	{
		item = L->array[pos];
		for (int idx = pos; idx < (L->size - 1); idx++)
			L->array[idx] = L->array[idx + 1];
		L->size--;
		return (item);
	}
}
```