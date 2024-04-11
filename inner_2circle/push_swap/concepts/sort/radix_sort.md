# 기수 정렬 (radix sort)

## 기수 정렬 시작하기

### 기수 정렬이란?

- 기수 (radix) : 숫자의 자릿수
- 기수 정렬 : 자릿수의 값에 따라서 정렬하는 다단계 정렬 방식
    - 단계의 수는 데이터의 자릿수의 개수와 일치한다.

### 기수 정렬의 원리(와 장점)

- 예시로 이해하기
    - 한자리로만 이뤄진 십진수의 숫자들 정렬하기
        - 십진수에서 각 자릿수는 0에서 9까지의 값을 가짐
        - 한자리 숫자들의 비교는 10개의 버킷을 만들어 입력 데이터의 각 자릿수의 값에 따라 버킷에 담음
        - 결과는 버킷 안에 들어있는 숫자를 순차적으로 읽어서 정렬 결과를 도출함
            
            ⇒ 자릿수의 값에 따라 버킷에 넣고 (초기 버킷에 담기) 빼는 (정렬을 위해 내용물 빼기) 작업만 반복
            (비교 연산을 전혀 사용하지 않음)
            
    - 여러 자리로 이뤄진 십진수 숫자들 (두자릿수) 정렬하기
        - 일의 자릿수에 대해서 0 ~ 9까지의 버킷에 담고 0부터 9까지의 결과는 빼는 작업을 진행함
        (일의 자릿수에 대해서는 십의 자릿수와 상관 없이 일단 정렬이 된 상태)
        - 십의 자릿수에 대해서 0 ~ 9까지의 버킷에 담고 버킷에 담긴 결과를 빼는 작업을 진행함
        (버킷 내 값들 중에서는 이미 이전 단계에서 일의 자릿수를 정렬했기에 작은 값부터 순차적으로 담김)
        
        ⇒ 낮은 자릿수로 정렬한 다음 차츰 높은 자릿수로 정렬함
        
        - LSD (Least Significant Digit) : 가장 낮은 자릿수
        - MSD (Most Significant Digit) : 가장 높은 자릿수
- 기수 정렬은 레코드를 비교하지 않고도 정렬하는 방법이다.
(입력 데이터에 대해서 어떤 비교 연산도 실행하지 않고 데이터를 정렬할 수 있는 정렬 기법)
    - 다른 정렬들은 레코드들을 비교해서 정렬하는 방식이기에 비교가 불가능한 레코드들은 정렬할 수 없다.
        
        ⇒ $O(\log_2(n))$의 시간 복잡도 이하로 최적화할 수 없음
        
    - 기수 정렬은 O(kn)의 시간 복잡도를 가지며, k는 대부분 4 이하이다.
        
        ⇒ 다른 정렬들이 가지는 복잡도의 하한선 $O(\log_2(n))$을 깰 수 있음
        

### 기수 정렬의 단점

- 기수 정렬은 추가적인 메모리를 필요로 한다.
    
    하지만 이를 감안하더라도 다른 정렬 기법보다 빠르기 때문에 인기 있는 정렬 기법 중 하나다.
    
- 다른 정렬들은 모든 종류의 키 형태를 적용할 수 있으나 기수 정렬은 정렬 가능한 레코드의 타입이 한정된다.
(기수 정렬을 사용하려면 레코드의 키들이 동일한 길이를 가지는 숫자나 문자열로 구성되어야 한다)
    - 정렬에 사용되는 키값 (bucket에 담길 수 있는 값)이 숫자로 표현되어야 적용이 가능하다.
    - 한글, 한자, 실수 등의 키 값을 기수 정렬로 표현해야 한다면 매우 많은 버킷이 필요하기에 기수 정렬 적용이 불가능하다

## 기수 정렬의 알고리즘

- 버킷 : 큐의 형태를 갖추고 있어야 함 (구체적으로는 원형 큐의 형태를 갖고 있어야 한다)

### 의사 코드

```c
radix_sort(list, n)
{
	1. 0 ~ 9까지의 값을 담은 버킷 생성 (Q. 버킷 크기는 어떻게 생성할 것인가)
	2. LSD부터 MSD까지 각 자릿수를 확인하는 반복을 진행하며 과정을 수행함
		for (int d = LSD; d <= MSD; d++)   // d = 자릿수를 비교할 일종의 인덱스
		{
			2-1. 0 ~ 9의 버킷에 각각의 자릿수를 담음
			2-2. 다시 0 ~ 9의 버킷에 담긴 레코드를 list에 붙여넣기
		}
}

/* 버킷 자료 구조 설정
* 버킷은 선입 선출이 되어야 한다 => 큐 자료구조
* 2-1의 버킷에 자료를 담는 행위 => 큐 삽입 연산
* 2-2의 버킷에 담긴 자료를 list에 붙여넣는 행위 => 큐 삭제 연산 (반환값 list 순차 담기)
*/
```

### 코드 구현

```c
// 필요한 헤더 파일 붙여오기
#include <stdio.h>
#include <stdlib.h>

// 매크로, typedef, 구조체 설정
#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct {                // 큐 (배열과 빼기 위한 front, 담기 위한 rear)
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} type_queue;

// 함수 프로토 타입 명시
void ft_error(char *message);
void init_queue(type_queue *q);
int is_empty(type_queue *q);
int is_full(type_queue *q);
void enqueue(type_queue *q, element item);
elemenet dequeue(type_queue *q);

#defin SIZE 10
int main(void)
{
	int list[SIZE];
	srand(time(NULL));
	for (int i=0; i<SIZE; i++)
		list[i] = rand() % 100;
		
	radix_sort(list, SIZE);
	return (0);
}
// 오류 함수
void ft_error(char *message)
{
	printf("%s\n", message);
	exit(1);
}

// 큐 연산 관련 함수
void init_queue(type_queue *q)
{
	q -> front = 0;
	q -> rear = 0;
	// q -> front = q -> rear = 0; 으로 한줄 줄이기 가능
}

int is_empty(type_queue *q)
{
	int boolean;
	
	boolean = (q->front == q->rear) ? 1 : 0;
	return (boolean);
}

int is_full(type_queue *q)
{
	int boolean;
	
	boolean = ((q->rear + 1) % MAX_QUEUE_SIZE == (q->front)) ? 1 : 0;
	return (boolean);
}

void enqueue(type_queue *q, element item)
{
	if (is_full(q))
		ft_error("queue is full. cannot input item in queue.");
	// rear++로 끝내기에는 rear가 MAX_QUEUE_SIZE 였을 경우를 방지하기 위해 나머지값 이용
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

elemenet dequeue(type_queue *q)
{
	if (is_empty(q))
		ft_eroor("queue is empty, cannot delete element");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return (q->data[q->front]);
}

// 기수 정렬 관련 함수
	// 매크로 (BUCKETS = 진수가 가질 수 있는 값, DIGITS = 요소의 자릿수)
#define BUCKERS 10
#define DIGITS 4

void radix_sort(int list[], int n)
{
	
	int idx, bucket, digit;
	int factor = 1;                // 자릿수 확인을 위해 나누는 인자
	
	// 큐 자료형의 버켓들을 담은 배열 생성 및 버켓 초기화
	type_queue queues[BUCKETS];
	for (bucket=0; bucket<BUCKETS; bucket++)
		init_queue(&queues[bucket]);
	
	// 자릿수마다 버켓 큐 삽입 -> 큐 삭제
	for (digit=0; digit<DIGITS; digit++)
	{
		for (idx = 0; idx < n; idx++)
			enqueue(&queues[(list[idx] / factor) % 10], list[idx]);
			// list의 i 번째 인덱스의 자릿수값에 해당하는 버켓에 list[i]를 삽입
		
		idx = 0;
		for (bucket = 0; bucket < BUCKETS; bucket++)
		{
			while (is_empty(&queues[bucket]) != NULL)
				list[idx++] = dequeue(&queues[bucket]);
		}
		factor *= 10;
	}
}
```

## 기수 정렬 분석

- 기수 정렬의 시간 복잡도는 O(d * n)
    - 자릿수의 개수 d번만큼 외부 반복문을 돈다.
    - 정수의 개수 n번만큼 내부 반복문을 돈다.
- 일반적으로 컴퓨터 안에서 정수의 크기를 제한하기에 32비트의 컴퓨터의 경우에는 대개 10개 정도의 자릿수를 가지기에 10 정도의 값을 갖는 d는 n에 비해 작은 수가 된다.
    
    ⇒ O(n)이라고 봐도 무방하다